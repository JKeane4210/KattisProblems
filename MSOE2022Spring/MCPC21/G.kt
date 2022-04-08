import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val ln = readLine()!!.toCharArray()
        var pss = false
        for (i in 0 until 7) {
            if (verify(ln, i)) {
                println(1)
                pss = true
                break
            }
        }
        if (!pss) {
            println(0)
        }
    }
}

private fun verify(c: CharArray, i: Int): Boolean {
    var end = i
    while (end < c.size + 7) {
        val ba = BooleanArray(26)
        for (q in max(0, end - 7) until min(end, c.size)) {
            if (ba[c[q] - 'A']) {
                return false
            }
            ba[c[q] - 'A'] = true
        }
        end += 7
    }
    return true
}
