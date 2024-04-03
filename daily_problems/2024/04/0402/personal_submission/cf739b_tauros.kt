private fun solve() {
    // https://codeforces.com/problemset/problem/739/B
    // https://codeforces.com/problemset/submission/739/254697954
    // 相对位置转换为绝对位置进行比对，可以使用树上差分
    val n = rd.ni()
    val vtx = rd.na(n)
    val graph = IGraph(n, n - 1)
    repeat(n - 1) {
        val (p, w) = rd.ni() - 1 to rd.ni()
        graph.addEdge(p, it + 1, w)
    }

    val diff = iar(n)
    run {
        val (stack, dist) = iar(n) to lar(n)
        var top = 0
        fun IGraph.dfs(u: int = 0, d: long = 0) {
            val idx = findFirst(top) { d - dist[stack[it]] <= vtx[u] }
            if (top > 0) diff[stack[top - 1]] += 1
            if (idx > 0) diff[stack[idx - 1]] -= 1
            stack[top++] = u; dist[u] = d
            each(u) {
                val (v, w) = to[it] to weight[it]
                dfs(v, d + w)
            }
            top--
        }
        graph.dfs()
    }
    val ans = iar(n)
    fun IGraph.dfs(u: int = 0) {
        each(u) {
            val v = to[it]
            dfs(v)
            ans[u] += ans[v]
        }
        ans[u] += diff[u]
    }
    graph.dfs()

    for (res in ans) wt.print("$res ")
    wt.println()
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}