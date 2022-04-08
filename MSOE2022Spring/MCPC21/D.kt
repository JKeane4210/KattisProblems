import kotlin.math.abs
import kotlin.system.exitProcess

typealias PD = Pair<Double, Double>

private inline val PD.x: Double
    get() = first
private inline val PD.y: Double
    get() = second

private const val EPS = 1e-6

fun main() {
    val nPts = readLine()!!.toInt()
    val pts = Array(nPts) { readLine()!!.split(" ").map(String::toDouble).run { this[0] to this[1] } }
    val areas = DoubleArray(nPts)
    var total = 0.0
    for (i in 2 until nPts) {
        areas[i] = ta(pts[0], pts[i - 1], pts[i])
        total += areas[i]
    }
    val half = total / 2
    var cur = 0.0
    var limit = 2
    while (cur + areas[limit] <= half) {
        cur += areas[limit]
        limit++
    }
    val upForGrab = areas[limit]
    val needed = half - cur
    val proportion = needed / upForGrab
    val ansX = pts[limit - 1].x + (pts[limit].x - pts[limit - 1].x) * proportion
    val ansY = pts[limit - 1].y + (pts[limit].y - pts[limit - 1].y) * proportion

    println("$ansX $ansY")

//    fun ans(pd: PD): Nothing {
//        println("${pd.x} ${pd.y}")
//        exitProcess(0)
//    }

//    if (areas[2] >= areas.last()) {
//        ans(solveOn(0.0, 0.0, pts[0], pts[1], pts[2], areas.last()))
//    } else {
//        for (i in 2 until nPts) {
//            if (2 * areas[i - 1] <= areas.last() && 2 * areas[i] >= areas.last()) {
//                System.err.println("on line seg $i: (${pts[i - 1].x}, ${pts[i - 1].y}) to (${pts[i].x}, ${pts[i].y})")
//                ans(solveOn(areas[i - 1], areas.last() - areas[i], pts[0], pts[i - 1], pts[i], areas.last()))
//            }
//        }
//    }
}

private fun solveOn(pointASideArea: Double, pointBSideArea: Double, door: PD, pa: PD, pb: PD, ta: Double): PD {
    val areaUpForGrabs = ta - pointASideArea - pointBSideArea
    val pA = (ta / 2.0 - pointASideArea) / areaUpForGrabs
    val x = pa.x * pA + (1 - pA) * pb.x
    val y = pa.y * pA + (1 - pA) * pb.y
    return x to y


//    if (abs(pointASideArea - pointBSideArea) <= EPS) {
//        return if (abs(pa.x - pb.x) <= EPS) {
//            pa.x to ((pa.y + pb.y) / 2.0)
//        } else if (abs(pa.y - pb.y) <= EPS) {
//            ((pa.x + pb.x) / 2.0) to pa.y
//        } else {
//            val slope = (pb.y - pa.y) / (pb.x - pa.x)
//            val dx = pb.x - pa.x
//            val dy = pb.y - pa.y
//            val dist = sqrt((dx * dx) + (dy * dy))
//
//            TODO()
//        }
//    } else {
//        TODO()
//    }
}

fun ta(pa: PD, pb: PD, pc: PD): Double {
    val sa = (pa.first * pb.second) - (pb.first * pa.second)
    val sb = (pb.first * pc.second) - (pc.first * pb.second)
    val sc = (pc.first * pa.second) - (pa.first * pc.second)
    return abs(sa + sb + sc) / 2.0
}
