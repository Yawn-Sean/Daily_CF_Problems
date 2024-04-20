private fun solve() {
    // https://codeforces.com/problemset/problem/662/B
    // https://codeforces.com/problemset/submission/662/257282963
    // 不会，学习一下，经典的枚举点灯问题
    val (n, m) = rd.ni() to rd.ni()
    val graph = IGraph(n, m * 2)
    repeat(m) {
        val (u, v) = rd.ni() - 1 to rd.ni() - 1
        val c = if (rd.nc() == 'R') 0 else 1
        graph.addEdge(u, v, c); graph.addEdge(v, u, c)
    }

    var (cnt, ans) = -1 to mlo<int>()
    fun fill(all: int) {
        val (vis, flip) = bar(n) to iar(n) { -1 }
        val res = mlo<int>()
        var fail = false
        for (i in 0 until n) if (!vis[i]) {
            fun search(op: int): Pair<List<int>, boolean> {
                val (clear, ops) = mlo<int>() to mlo<int>()
                fun dfs(u: int, f: int): boolean {
                    if (flip[u] != -1) return flip[u] == f
                    vis[u] = true; clear.add(u);
                    flip[u] = f; if (f == 1) ops.add(u)
                    var success = true
                    graph.eachBreakable(u) {
                        val (v, c) = graph.to[it] to graph.weight[it]
                        val next = c xor all xor f
                        if (!dfs(v, next)) {
                            success = false
                            return@eachBreakable true
                        }
                        false
                    }
                    return success
                }
                val success = dfs(i, op)
                for (u in clear) flip[u] = -1
                return ops to success
            }
            val (eList, eRes) = search(0)
            val (oList, oRes) = search(1)
            if (!eRes && !oRes) {
                fail = true; break
            }
            if (eRes xor oRes) res.addAll(if (eRes) eList else oList)
            else res.addAll(if (eList.size < oList.size) eList else oList)
        }
        if (!fail) {
            if (cnt == -1 || res.size < cnt) {
                cnt = res.size; ans = res
            }
        }
    }
    fill(0); fill(1)
    wt.println(cnt)
    if (cnt != -1) {
        for (res in ans) wt.print("${res + 1} ")
        wt.println()
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}