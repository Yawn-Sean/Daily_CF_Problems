private fun somethingWithXor(n: Int) {
    val nums1 = IntArray(n) { query(0, it) }
    val nums2 = IntArray(n) { query(it, 0) }
    var count = 0
    val p = IntArray(n)
    val b = IntArray(n)
    fun check(): Boolean {
        for (i in 0 until n) {
            if (p[i] < 0 || p[i] >= n || b[i] < 0 || b[i] >= n || p[b[i]] != i) {
                return false
            }
        }
        return true
    }
    val result = mutableListOf<Int>()
    for (p0 in 0 until n) {
        p.fill(-1)
        b.fill(-1)
        p[0] = p0
        for (j in 0 until n) {
            b[j] = nums1[j].xor(p0)
        }
        for (i in 0 until n) {
            p[i] = nums2[i].xor(b[0])
        }
        if (check()) {
            count++
            if (result.isEmpty()) {
                result.addAll(p.toList())
            }
        }
    }
    writer.println("!")
    writer.println(count)
    writer.printNums(result)
    writer.flush()
}

private fun query(i: Int, j: Int): Int {
    writer.println("? $i $j")
    writer.flush()
    return readInt()
}
