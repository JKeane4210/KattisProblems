fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val probs = DoubleArray(n) { br.readLine().toDouble() }
    val dp = DoubleArray(1 shl n)
    val productsA = DoubleArray(1 shl n)
    val productsB = DoubleArray(1 shl n)
    productsA[0] = 1.0
    productsB[0] = 1.0
    for (i in 1 until (1 shl n)) {
        val lowBit = Integer.lowestOneBit(i)
        val idx = Integer.numberOfTrailingZeros(lowBit)
        productsA[i] = probs[idx] * productsA[i xor lowBit]
        productsB[i] = (1.0 - probs[idx]) * productsB[i xor lowBit]
    }


    for (state in 1 until (1 shl n)) {
        if (Integer.bitCount(state) <= 2) continue
        val partialProbAs = DoubleArray(n)
        val partialProbBs = DoubleArray(n)

        for (i in 0 until n) {
            if ((1 shl i) and state != 0) {
                partialProbAs[i] = (1.0 - probs[i]) * productsA[state xor (1 shl i)]
                partialProbBs[i] = probs[i] * productsB[state xor (1 shl i)]
            }
        }
        val probSum = partialProbAs.sum() + partialProbBs.sum()
        dp[state] = 1 / probSum
        for (i in 0 until n) {
            if ((1 shl i) and state != 0) {
                val newState = state xor (1 shl i)
                dp[state] += (partialProbAs[i] + partialProbBs[i]) * dp[newState] / probSum
            }
        }
//        var temp = state
//        while (temp != 0) {
//            val bit = Integer.lowestOneBit(temp)
//            val idx = Integer.numberOfTrailingZeros(bit)
//            var temp2 = state
//            wh
//        }
    }
//    var ans = 0.0
//    for (i in 0 until n) {
//        ans += dp[((1 shl n) - 1) xor (1 shl i)]
//    }
    println(dp.last())
}