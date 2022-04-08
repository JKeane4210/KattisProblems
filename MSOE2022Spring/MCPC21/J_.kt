fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    var (n, m) = br.readLine().split(" ").map { it.toInt() }
    val sizes = IntArray(m) { br.readLine().toInt() }
    val ans = IntArray(m)
    var i = 0
    var streak = 0
    while (n > 0 && streak < m) {
        if (i == m) i = 0
        if (sizes[i] > 0) {
            n--
            sizes[i]--
            ans[i]++
            streak = 0
        } else {
            streak++
        }
        i++
    }
    for (j in 0 until m) {
        bw.append("${ans[j]}\n")
    }
    bw.flush()
}