private fun solve() {
    // https://codeforces.com/problemset/problem/916/C
    // https://codeforces.com/problemset/submission/916/256223535
    // 乱搞，1-n直接是2，其它的找个最小的大于等于2+(n-2)的质数，然后分配到生成树里就好
    // 剩余的边全1e9
    val (n, m) = rd.ni() to rd.ni()
    val cap = 1e6.toInt()
    val primes = Prime(cap)

    val idx = findFirst(primes.size) { primes[it] >= n }
    var mst = primes[idx] - 2
    val inf = 1e9.toInt()
    val edges = buildList {
        add(iao(1, n, 2))
        for (i in 2 until n - 1) {
            add(iao(1, i, 1))
            mst -= 1
        }
        if (mst > 0) add(iao(1, n - 1, mst))
        var cnt = m - (n - 1)
        for (i in 2 until n) {
            if (cnt == 0) break
            for (j in i + 1 .. n) {
                if (cnt == 0) break
                add(iao(i, j, inf))
                cnt -= 1
            }
        }
    }
    wt.println("2 ${primes[idx]}")
    for ((u, v, w) in edges) {
        wt.println("$u $v $w")
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}