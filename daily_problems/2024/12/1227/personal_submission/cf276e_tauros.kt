private fun solve() {
    // https://codeforces.com/problemset/submission/276/299157996
    // 竟然1A，惊了
    val (n, q) = rd.na(2)
    val graph = Graph(n)
    repeat(n - 1) {
        val (u, v) = rd.na(2).map { it - 1 }
        graph.addEdge(u, v); graph.addEdge(v, u)
    }
    

    fun IntArray.update(pos: int, add: int) = this.bitUpdateWithIndex(pos) { this[it] += add }
    fun IntArray.query(pos: int) = this.bitQuery(pos, 0, int::plus)

    val (dep, head) = iar(n) to iar(n)
    val bit = mutableMapOf<int, IntArray>().default { iar(0) }
    fun Graph.dfs(u: int, fa: int = -1, d: int = 1, top: int = 0): int {
        dep[u] = d; head[u] = top
        var len = d
        each(u) {
            val v = to[it]
            if (v == fa) {
                return@each
            }
            len = maxOf(len, dfs(v, u, d + 1, if (u == 0) v else top))
        }
        if (fa == 0) {
            bit[u] = iar(len + 2)
        }
        return len
    }
    val maxDep = graph.dfs(0)
    val total = iar(maxDep + 2)

    repeat(q) {
        val op = rd.ni()
        if (op == 0) {
            val (v, x, d) = iao(rd.ni() - 1, rd.ni(), rd.ni())
            if (v == 0) {
                total.update(1, x); total.update(minOf(maxDep, 1 + d) + 1, -x)
            } else {
                val up = dep[v] - d
                val (top, bottom) = maxOf(2, up) to minOf(bit[head[v]].size - 2, dep[v] + d)
                bit[head[v]].update(top, x); bit[head[v]].update(bottom + 1, -x)
                if (up <= 1) {
                    val all = 2 - up
                    val down = minOf(all, maxDep)
                    total.update(1, x); total.update(down + 1, -x)
                    bit[head[v]].update(1, -x); bit[head[v]].update(down + 1, x)
                }
            }
        } else {
            val v = rd.ni() - 1
            val ans = if (v == 0) {
                total.query(1)
            } else {
                val tot = total.query(dep[v])
                val branch = bit[head[v]].query(dep[v])
                tot + branch
            }
            wt.println(ans)
        }
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}
