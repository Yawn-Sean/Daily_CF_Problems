private fun solve() {
    // https://codeforces.com/problemset/problem/1525/E
    // https://codeforces.com/problemset/submission/1525/258260769
    // 反过来计算每个点不被覆盖的情况，不会算，学的官解
    val (n, m) = rd.ni() to rd.ni()
    val dist = ar(m) { iar(n) }
    repeat(n) { i ->
        val d = rd.na(m)
        for (j in 0 until m) dist[j][i] = d[j]
    }

    withMod(998244353) {
        val comb = ModComb(n + 1)
        var contribute = mint.ZERO
        val total = comb.fac[n].toMInt()
        val cnt = iar(n + 2)
        for (i in 0 until m) {
            cnt.fill(0)
            for (j in 0 until n) cnt[dist[i][j]] += 1
            var (res, sum) = mint.ONE to mint.ZERO
            for (d in n downTo 1) {
                sum += cnt[d + 1]
                res *= (sum - (n - d))
            }
            contribute += total - res
        }
        val ans = contribute / total
        wt.println(ans)
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}