import javax.print.attribute.IntegerSyntax
import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()

    val nums = IntArray(n) { br.readLine().toInt() }

    val best = solve(0, 0, 0, n, nums)
    println(n - best)
//    val xors = Array(nums.size) { a -> IntArray(nums.size) { b -> nums[a] xor nums[b] } }
}

fun solve(idx: Int, size: Int, included: Int, n: Int, nums: IntArray): Int {
    if (idx == n) {
        return size
    }
    var canAdd = true
    var temp = included
    while (temp != 0) {
        val bit = Integer.lowestOneBit(temp)
        val i = Integer.numberOfTrailingZeros(temp)
        temp = temp xor bit
        var temp2 = temp
        while (temp2 != 0) {
            val bit2 = Integer.lowestOneBit(temp2)
            val j = Integer.numberOfTrailingZeros(bit2)
            temp2 = temp2 xor bit2

            if(nums[i] xor nums[j] == nums[idx]) {
                canAdd = false
                temp = 0
                temp2 = 0
            }
        }
    }
//    for (i in 0 until idx) {
//        if ((1 shl i) and included != 0) {
//            for (j in i + 1 until idx) {
//                if ((1 shl j) and included != 0) {
//                    if (nums[i] xor nums[j] == nums[idx]) {
//                        canAdd = false
//                    }
//                }
//            }
//        }
//    }
    var best = solve(idx + 1, size, included, n, nums)

    if (canAdd) {
        best = max(best, solve(idx + 1, size + 1, included or (1 shl idx), n, nums))
    }
    return best
}