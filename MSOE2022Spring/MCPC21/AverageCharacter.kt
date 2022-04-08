import kotlin.math.floor

fun main() {
    val s = readLine()!!.map { it - ' ' }.average()
    println(' ' + floor(s).toInt())
}