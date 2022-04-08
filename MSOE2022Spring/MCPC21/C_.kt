fun main() {
    val br = System.`in`.bufferedReader()
    val (n, k, t) = br.readLine().split(" ").map { it.toInt() }
    val dp = Array(n + 1) { Array(k + 1) { DoubleArray(t + 1) } }
    val probs = DoubleArray(n)
    val times = IntArray(n)
    for (i in 0 until n) {
        val (a, b) = br.readLine().split(" ")
        probs[i] = a.toDouble()
        times[i] = b.toInt()
    }
    val sorted = (0 until n).sortedBy { i -> times[i] }.toIntArray()
    dp[0][0][0] = 1.0
    val ans = DoubleArray(n)
    for (i in 0 until n) {
        val s = sorted[i]
        val pSolve = probs[s]
        for (alreadyIn in 0 until k) {
            val leftToConsider = n - i
            val leftToInclude = k - alreadyIn
            if (leftToInclude <= leftToConsider) { // include it
                val pInclude = leftToInclude.toDouble() / leftToConsider
                for (curTime in 0..t - times[s]) {
                    dp[i + 1][alreadyIn + 1][curTime + times[s]] += dp[i][alreadyIn][curTime] * pInclude * pSolve
                    ans[s] += dp[i][alreadyIn][curTime] * pInclude * pSolve
                    dp[i + 1][alreadyIn + 1][curTime] += dp[i][alreadyIn][curTime] * pInclude * (1 - pSolve)
                }
                for (curTime in t - times[s] + 1..t) {
                    dp[i + 1][alreadyIn + 1][curTime] += dp[i][alreadyIn][curTime] * pInclude
                }
            }
            if (leftToInclude < leftToConsider) { // don't include it
                val pNotInclude = (leftToConsider - leftToInclude).toDouble() / leftToConsider
                for (curTime in 0..t) {
                    dp[i + 1][alreadyIn][curTime] += dp[i][alreadyIn][curTime] * pNotInclude
                }
            }
        }
    }
    for (i in 0 until n) {
        ans[i] *= n.toDouble() / k
    }
    println(ans.joinToString("\n"))
}