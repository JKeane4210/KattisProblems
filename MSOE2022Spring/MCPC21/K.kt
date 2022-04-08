import java.io.PrintStream
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

fun main() {
    val gs = readLine()!!.toInt()
    val arr = Array(gs + 1) { readLine()!!.toCharArray() }

    val gr = Grid(gs, arr)

    val prs = listOf(
        (0 to 0) to (1 to 1),
        (gs to 0) to (gs - 1 to 1),
        (gs to gs) to (gs - 1 to gs - 1),
        (0 to gs) to (1 to gs - 1)
    )
    for ((numCoord, placeCoord) in prs) {
        if (arr[numCoord.first][numCoord.second] == '1') {
            gr.join(numCoord, placeCoord)
        }
    }

    for (i in 1 until gs) {
        if (arr[0][i] == '2') {
            gr.join(0 to i, 1 to i - 1)
            gr.join(0 to i, 1 to i + 1)
        }
        if (arr[gs][i] == '2') {
            gr.join(gs to i, gs - 1 to i - 1)
            gr.join(gs to i, gs - 1 to i + 1)
        }
        if (arr[i][0] == '2') {
            gr.join(i to 0, i + 1 to 1)
            gr.join(i to 0, i - 1 to 1)
        }
        if (arr[i][gs] == '2') {
            gr.join(i to gs, i + 1 to gs - 1)
            gr.join(i to gs, i - 1 to gs - 1)
        }
    }

    for (x in arr.indices) {
        for (y in arr.indices) {
            if (arr[x][y] == '0') {
                gr.join(x to y - 1, x + 1 to y)
                gr.join(x to y + 1, x + 1 to y)
                gr.join(x to y - 1, x - 1 to y)
                gr.join(x to y + 1, x - 1 to y)
            }
            if (arr[x][y] == '4') {
                gr.join(x to y, x + 1 to y + 1)
                gr.join(x to y, x + 1 to y - 1)
                gr.join(x to y, x - 1 to y + 1)
                gr.join(x to y, x - 1 to y - 1)
            }
        }
    }

    gr.printAns(System.err)
    gr.doUpdateQueue()
    gr.printAns()
}

class Grid(private val gs: Int, val chars: Array<CharArray>) {
    val slashGrid = Array(gs) { CharArray(gs) { '?' } }
    val clsGrid = Array(gs + 1) { y -> Array(gs + 1) { x -> GridPos(y, x, mapCharToRequiredConns(chars[y][x])) } }
    val actuallyNeedsUpdate = Array(gs + 1) { BooleanArray(gs + 1) }
    val updateQueue = java.util.ArrayDeque<Pair<Int, Int>>()

    fun join(p1: Pair<Int, Int>, p2: Pair<Int, Int>) {
        require(abs(p1.first - p2.first) == 1 && abs(p1.second - p2.second) == 1) { "$p1 $p2" }
        val (minY, maxY) = if (p1.first < p2.first) p1 to p2 else p2 to p1
        val (placeX, placeY) = min(p1.second, p2.second) to min(p1.first, p2.first)
        if (placeX !in slashGrid.indices || placeY !in slashGrid.indices) return
        slashGrid[placeY][placeX] = if (minY.second < maxY.second) '\\' else '/'
        addUpdateSpot(placeY, placeX)
        addUpdateSpot(placeY + 1, placeX)
        addUpdateSpot(placeY, placeX + 1)
        addUpdateSpot(placeY + 1, placeX + 1)
    }
    
    fun addUpdateSpot(y: Int, x: Int) {
        if (actuallyNeedsUpdate[y][x]) return
        actuallyNeedsUpdate[y][x] = true
        updateQueue += y to x
    }

    fun safeGetCh(y: Int, x: Int): Char {
        if (y !in chars.indices || x !in chars.indices) return '+'
        return chars[y][x]
    }

    fun safeGetSl(y: Int, x: Int): Char {
        if (y !in slashGrid.indices || x !in slashGrid.indices) return '+'
        return slashGrid[y][x]
    }

    fun doUpdateQueue() {
        while (updateQueue.isNotEmpty()) {
            val (uy, ux) = updateQueue.poll()
            if (uy !in chars.indices || ux !in chars.indices) continue
            if (chars[uy][ux] != '+') {
                var goingIn = 0
                goingIn += if (safeGetSl(uy, ux) == '\\') 1 else 0
                goingIn += if (safeGetSl(uy + 1, ux + 1) == '\\') 1 else 0
                goingIn += if (safeGetSl(uy, ux + 1) == '/') 1 else 0
                goingIn += if (safeGetSl(uy + 1, ux) == '/') 1 else 0

                if (goingIn == chars[uy][ux] - '0') {

                } else {
                    var set = 0
                    set += if (safeGetSl(uy, ux) != '+') 1 else 0
                    set += if (safeGetSl(uy + 1, ux + 1) != '+') 1 else 0
                    set += if (safeGetSl(uy, ux + 1) != '+') 1 else 0
                    set += if (safeGetSl(uy + 1, ux) != '+') 1 else 0

                    if (set + 1 == goingIn) {
                        when {
                            safeGetSl(uy, ux) == '+' -> {
                                slashGrid[uy][ux] = '\\'
                            }
                            safeGetSl(uy, ux) == '+' -> {
                                slashGrid[uy][ux] = '\\'
                            }
                        }
                        addUpdateSpot(uy + 1, ux - 1)
                        addUpdateSpot(uy + 1, ux)
                        addUpdateSpot(uy + 1, ux + 1)
                        addUpdateSpot(uy, ux - 1)
                        addUpdateSpot(uy, ux)
                        addUpdateSpot(uy, ux + 1)
                        addUpdateSpot(uy - 1, ux - 1)
                        addUpdateSpot(uy - 1, ux)
                        addUpdateSpot(uy - 1, ux + 1)
                    }
                }
            }
            actuallyNeedsUpdate[uy][ux] = false
        }
    }

    fun printAns(ps: PrintStream = System.out) {
        slashGrid.forEach { ps.println(it.joinToString("")) }
    }

    companion object {
        private fun mapCharToRequiredConns(ch: Char): Int {
            return if (ch == '+') -1 else ch - '0'
        }
    }
}

class GridPos(val y: Int, val x: Int, var requiredConns: Int) {
    var currConns = 0

}

sealed class Pos {
    object Any : Pos()
    class Value(val value: Int) : Pos() {
        var currs = 0
        override fun equals(other: kotlin.Any?): Boolean {
            if (this === other) return true
            if (other !is Value) return false

            if (value != other.value) return false

            return true
        }

        override fun hashCode(): Int {
            return value
        }
    }

    companion object {
        fun map(ch: Char): Pos {
            return if (ch == '+') Any else Value(ch - '0')
        }
    }
}
