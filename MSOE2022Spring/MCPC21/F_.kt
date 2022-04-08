fun main() {
    val br = System.`in`.bufferedReader()
    val (n, k) = br.readLine().split(" ").map { it.toInt() }
    val connected = Array(k shl 1) { BooleanArray(k shl 1) }
//    fun dfsA(node: Int, visited: BooleanArray, order: IntArray, next: Int): Int {
//        visited[node] = true
//        var curNext = next
//        for (adj in 0 until (k shl 1)) {
//            if (connected[node][adj] && !visited[adj]) {
//                curNext = dfsA(adj, visited, order, curNext)
//            }
//        }
//        order[curNext++] = node
//        return curNext
//    }
//
//    fun dfsB(node: Int, components: IntArray, component: Int) {
//        components[node] = component
//        for (adj in 0 until (k shl 1)) {
//            if (connected[adj][node] && components[adj] == -1) {
//                dfsB(adj, components, component)
//            }
//        }
//    }

    repeat(n) {
        val line = br.readLine()
        for (i in 0 until k) {
            if (line[i] != 'X') {
                val agreeI = if (line[i] == 'F') i else k + i
                val disagreeI = if (line[i] == 'F') k + i else i
                for (j in i + 1 until k) {
                    if (line[j] != 'X') {
                        val agreeJ = if (line[j] == 'F') j else k + j
                        val disagreeJ = if (line[j] == 'F') k + j else j
                        connected[agreeI][disagreeJ] = true
                        connected[agreeJ][disagreeI] = true
                    }
                }
            }
        }
    }
    for (i in 0 until (k shl 1)) {
        connected[i][i] = true
    }
    for (u in 0 until (k shl 1)) {
        for (i in 0 until (k shl 1)) {
            for (j in 0 until (k shl 1)) {
                connected[i][j] = connected[i][j] || ( connected[i][u] && connected[u][j])
            }
        }
    }
    var good = true
    for (i in 0 until k) {
        if (connected[i][i + k] && connected[i + k][i]) {
            good = false
        }
    }
    if (good) {
        val ans = CharArray(k) { 'X' }
        for (i in 0 until k) {
            if (ans[i] == 'X') {
                val queue = java.util.ArrayDeque<Int>()
                if (connected[i][i + k]) {
                    ans[i] = 'T'
                    queue += i + k
                } else {
                    ans[i] = 'F'
                    queue += i
                }
                while (queue.isNotEmpty()) {
                    val node = queue.poll()
                    for (j in 0 until (k shl 1)) {
                        if (connected[node][j]) {
                            ans[j % k] = if (j < k) {
                                'F'
                            } else {
                                'T'
                            }
                        }
                    }
                }
            }
        }
        println(ans.joinToString(""))
    } else {
        println(-1)
    }
//    val order = IntArray(k shl 1)
//    var curIdx = 0
//    val visited = BooleanArray(k shl 1)
//    for (i in 0 until (k shl 1)) {
//        if (!visited[i]) {
//            curIdx = dfsA(i, visited, order, curIdx)
//        }
//    }
//
//    val componentIds = IntArray(k shl 1) { -1 }
//    var numComponents = 0
//    for (i in (k shl 1) - 1 downTo 0) {
//        if (componentIds[order[i]] == -1) {
//            dfsB(order[i], componentIds, numComponents++)
//        }
//    }
//    val reps = IntArray(numComponents) { k shl 1 }
//    for (i in 0 until (k shl 1)) {
//        reps[componentIds[i]] = min(reps[componentIds[i]], i)
//    }
//
//    var good = true
//    for (i in 0 until k) {
//        if (componentIds[i] == componentIds[k + i]) {
//            good = false
//        }
//    }
//    if (good) {
//        val pq = PriorityQueue<Int> { a, b ->
//            var ret = 0
//            for(i in 0 until k) {
//                ret = if(componentIds[i] == a) {
//                    -1
//                } else if(componentIds[i] == b) {
//                    1
//                } else if(componentIds[i + k] == a) {
//                    1
//                } else if(componentIds[i + k] == b) {
//                    -1
//                } else 0
//                if(ret != 0) break
//            }
//            ret
////            reps[a].compareTo(reps[b])
//        }
//        val totalOutOf = IntArray(numComponents)
//        val ans = CharArray(n) { 'X' }
//        for (i in 0 until (k shl 1)) {
//            for (j in 0 until (k shl 1)) {
//                if (connected[i][j] && componentIds[i] != componentIds[j]) {
//                    totalOutOf[componentIds[i]]++
//                }
//            }
//        }
//        for (i in 0 until numComponents) {
//            if (totalOutOf[i] == 0) {
//                pq += i
//            }
//        }
//
//        while (pq.isNotEmpty()) {
//            val component = pq.poll()
//            if (ans[reps[component] % k] == 'X') {
//                for (i in 0 until (k shl 1)) {
//                    if (componentIds[i] == component) {
//                        if (i >= k) {
//                            ans[i - k] = 'T'
//                        } else {
//                            ans[i] = 'F'
//                        }
//                        for (j in 0 until (k shl 1)) {
//                            if (connected[j][i] && componentIds[j] != component) {
//                                if (--totalOutOf[componentIds[j]] == 0) {
//                                    pq += componentIds[j]
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        println(ans.joinToString(""))
//    } else {
//        println(-1)
//    }


}