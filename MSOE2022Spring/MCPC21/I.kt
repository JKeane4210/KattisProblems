fun main() {
    val br = System.`in`.bufferedReader()
    val nums = IntArray(br.readLine().toInt()) { br.readLine().toInt() }
    val nSet = nums.toHashSet()
    val xors = Array(nums.size) { a -> IntArray(nums.size) { b -> nums[a] xor nums[b] } }
    val nti = IntArray(nums.size)
    for (i in nums.indices) {
        for (j in i + 1 until nums.size) {
            for (k in j + 1 until nums.size) {
                if (nums[i] xor nums[j] == nums[k]) {
                    for (o in nums.indices) {
                        if (o == i || o == j || o == k) continue
                        ++nti[o]
                    }
                }
            }
        }
    }
    println(nti.joinToString(" "))
}
