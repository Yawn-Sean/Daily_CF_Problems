private fun solve() {
    // https://codeforces.com/problemset/problem/500/D
    // https://codeforces.com/problemset/submission/500/257851089
    // 算下每条边的贡献，分别考虑一个点在子树外面和一个点在子树里面的情况
    // 贡献的系数不会变，变得只有边长
    val n = rd.ni()
    val graph = Graph(n, (n - 1) * 2)
    val edge = iar((n - 1) * 2)
    repeat(n - 1) {
        val (u, v, w) = iao(rd.ni() - 1, rd.ni() - 1, rd.ni())
        edge[graph.addEdge(u, v)] = w
        edge[graph.addEdge(v, u)] = w
    }

    val coe = lar((n - 1) * 2)
    fun Graph.dfs(u: int, fa: int): int {
        var size = 1
        each(u) {
            val v = to[it]
            if (v == fa) return@each
            val subSize = dfs(v, u)
            val rest = n - subSize
            val subOne = (rest - 1L) * rest / 2 * subSize * 2
            val outOne = (subSize - 1L) * subSize / 2 * rest * 2
            coe[it] = subOne + outOne; coe[it xor 1] = subOne + outOne
            size += subSize
        }
        return size
    }
    graph.dfs(0, -1)
    var total = (0 until (n - 1) * 2 step 2).map {
        coe[it].toDouble() * edge[it]
    }.reduce(double::plus)
    val divs = n * (n - 1L) * (n - 2L) / 6

    val q = rd.ni()
    repeat(q) {
        val (r, w) = (rd.ni() - 1) * 2 to rd.ni()
        val diff = edge[r] - w
        edge[r] = w; edge[r xor 1] = w
        total -= coe[r] * diff
        val ans = total / divs
        wt.printf("%.10f\n", ans)
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}