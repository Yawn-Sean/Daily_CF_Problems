private fun solve() {
    // https://codeforces.com/problemset/problem/1615/D
    // https://codeforces.com/problemset/submission/1615/257473122
    // 羊神的题解写得真好
    val cases = rd.ni()
    repeat(cases) {
        val (n, m) = rd.ni() to rd.ni()
        val tree = IGraph(n, (n - 1) * 2)
        repeat(n - 1) {
            val (u, v, w) = iao(rd.ni() - 1, rd.ni() - 1, rd.ni())
            tree.addEdge(u, v, w); tree.addEdge(v, u, w)
        }
        val mem = ar(m) { iao(rd.ni() - 1, rd.ni() - 1, rd.ni()) }

        val bel = iar(n) { -1 }
        val toHead = iar(n) { 0 }
        run {
            fun IGraph.dfs(u: int, fa: int, head: int, pre: int = 0) {
                bel[u] = head; toHead[u] = pre
                each(u) {
                    val (v, w) = to[it] to weight[it]
                    if (v == fa) return@each
                    dfs(v, u, if (w == -1) v else head, if (w == -1) 0 else pre xor w)
                }
            }
            tree.dfs(0, -1, 0)
        }
        var success = true
        val groupGraph = IGraph(n)
        for ((a, b, p) in mem) {
            val (toA, toB) = toHead[a] to toHead[b]
            val abXOR = toA xor toB
            val abXORp = abXOR.countOneBits() and 1
            val headXOR = abXORp xor p
            if (bel[a] == bel[b] && headXOR != 0) success = false
            groupGraph.addEdge(bel[a], bel[b], headXOR)
            groupGraph.addEdge(bel[b], bel[a], headXOR)
        }
        if (!success) {
            wt.println("NO"); return@repeat
        }
        val head = iar(n) { -1 }
        success = run {
            fun IGraph.dfs(u: int, fa: int, p: int): boolean {
                if (head[u] != -1) return head[u] == p
                if (head[u] == -1) head[u] = p
                each(u) {
                    val (v, w) = to[it] to weight[it]
                    if (v == fa) return@each
                    if (!dfs(v, u, w xor p)) return false
                }
                return true
            }
            for (i in 0 until n) if (head[i] == -1) {
                if (!groupGraph.dfs(i, -1, 0)) return@run false
            }
            true
        }
        if (!success) {
            wt.println("NO"); return@repeat
        }
        wt.println("YES")
        val ans = buildString {
            val pre = iar(n)
            fun IGraph.dfs(u: int, fa: int = -1) {
                each(u) {
                    val v = to[it]
                    if (v == fa) return@each
                    var w = weight[it]
                    if (w == -1) {
                        val rel = head[bel[u]] xor head[bel[v]]
                        w = rel xor toHead[u] xor toHead[v]
                    }
                    append("${u + 1} ${v + 1} $w\n")
                    pre[v] = pre[u] xor w
                    dfs(v, u)
                }
            }
            tree.dfs(0)
        }
        wt.print(ans)
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}