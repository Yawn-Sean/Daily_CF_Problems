private fun PrintWriter.solve() {
    val (m, n, q) = readInts(3)
    var result = m + n - 1
    val uf = UnionFindArray(m + n + 10)
    repeat(q) {
        val a = readInt()
        val b = readInt()
        if (!uf.connected(a, b + m)) {
            uf.union(a, b + m)
            result--
        }
    }
    println(result)
}
