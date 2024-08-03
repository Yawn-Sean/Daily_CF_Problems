private fun solve() {
    // https://codeforces.com/problemset/problem/1468/F
    // https://codeforces.com/problemset/submission/1468/254988417
    // 匹配一下反向的向量数量就可以
    val cases = rd.ni()
    fun id(x: FracLong, y: FracLong) = "$x#$y"
    val neg = FracLong(-1, 1)
    repeat(cases) {
        val n = rd.ni()
        val vectors = ar(n) {
            val (x, y, u, v) = rd.na(4)
            val vector = IPoint2(u, v) - IPoint2(x, y)
            val len2 = vector.len2()
            val (a, b) = vector
            ao(FracLong(a.toLong() * a * (if (a < 0) -1 else 1), len2), FracLong(b.toLong() * b * (if (b < 0 ) -1 else 1), len2))
        }
        val cnt = mmo<string, int>().default { 0 }
        var ans = 0L
        for ((a, b) in vectors) {
            val find = id(a * neg, b * neg)
            ans += cnt[find]
            cnt[id(a, b)] += 1
        }
        wt.println(ans)
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}