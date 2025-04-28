fun main() {
    val n = ri
    val k = ri
    val segs = mutableListOf(Pair(1, n))
    val a = ai(n)
    for (i in 0..<k) {
        a[i] = ri
        val (l, r) = segs.removeLast()
        if (a[i] !in l..r) {
            put(-1)
            done()
            return
        }
        if (a[i] != r) segs.add(Pair(a[i] + 1, r))
        if (a[i] != l) segs.add(Pair(l, a[i] - 1))
    }
    var j = k
    for ((l, r) in segs.reversed()) for (i in r downTo l) a[j++] = i
    put(*a.toTypedArray())
    done()
}
