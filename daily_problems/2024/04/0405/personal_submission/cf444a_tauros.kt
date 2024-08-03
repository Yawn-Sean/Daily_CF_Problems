private fun solve() {
    // https://codeforces.com/problemset/problem/444/A
    // https://codeforces.com/problemset/submission/444/255095308
    val (n, m) = rd.ni() to rd.ni()
    val vtx = rd.na(n)
    val edges = ar(m) { iao(rd.ni() - 1, rd.ni() - 1, rd.ni()) }

    var ans = 0.0
    for ((u, v, w) in edges) {
        val res = (vtx[u] + vtx[v]) / w.toDouble()
        ans = maxOf(res, ans)
    }
    wt.printf("%.12f\n", ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}