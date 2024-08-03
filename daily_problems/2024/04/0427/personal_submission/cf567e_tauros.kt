private fun solve() {
    // https://codeforces.com/problemset/problem/567/E
    // https://codeforces.com/problemset/submission/567/258464017
    // 非最短路改成最短路会，求必在最短路上的由于不会求桥边不会
    // 看了羊解 一个方法是求桥边 一个方法是哈希计数
    // 有重边需要判断下
    val (n, m, s, t) = iao(rd.ni(), rd.ni(), rd.ni() - 1, rd.ni() - 1)
    val (g, rg) = IGraph(n, m) to IGraph(n, m)
    val edges = ar(m) { IntArray(3) }
    repeat(m) {
        val (a, b, l) = iao(rd.ni() - 1, rd.ni() - 1, rd.ni())
        edges[it] = iao(a + 1, b + 1, l)
        g.addEdge(a, b, l); rg.addEdge(b, a, l)
    }

    val inf = 0x3f3f3f3f3f3f3f3fL
    fun IGraph.dij(st: int): LongArray {
        val (dist, vis) = lar(n) { inf } to bar(n)
        val heap = LIHeap()
        heap.offer(0L to st)
        dist[st] = 0
        while (heap.isNotEmpty()) {
            val (uDist, u) = heap.poll()
            if (vis[u]) continue
            vis[u] = true
            each(u) {
                val (v, w) = to[it] to weight[it]
                if (w + uDist < dist[v]) {
                    dist[v] = w + uDist
                    heap.offer(dist[v] to v)
                }
            }
        }
        return dist
    }

    val (sDist, tDist) = g.dij(s) to rg.dij(t)
    val shortest = sDist[t]
    val (tp, modify) = iar(m) to lar(m)
    val biGraph = IGraph(n)
    val biEdgeCnt = mmo<long, int>().default { 0 }
    for (i in 0 until m) {
        val (u, v) = rg.to[i] to g.to[i]
        val len = g.weight[i]
        val dist = sDist[u] + tDist[v] + len
        if (dist in shortest until inf) {
            if (dist == shortest) {
                biGraph.addEdge(u, v, i)
                biGraph.addEdge(v, u, i)
                val (x, y) = minOf(u, v) to maxOf(u, v)
                biEdgeCnt[x * n.toLong() + y] += 1
            }
            val diff = dist - (shortest - 1)
            if (len > diff) {
                tp[i] = 2; modify[i] = diff
            }
        }
    }
    val bridges = biGraph.bridges()
    for (i in bridges.bridgeIds) {
        val edgeId = biGraph.weight[i]
        val (u, v) = rg.to[edgeId] to g.to[edgeId]
        val (x, y) = minOf(u, v) to maxOf(u, v)
        if (biEdgeCnt[x * n.toLong() + y] == 1) {
            // 判下重边
            tp[edgeId] = 1
        }
    }

    for (i in 0 until m) {
        if (tp[i] == 0) {
            wt.println("NO")
        } else if (tp[i] == 1) {
            wt.println("YES")
        } else {
            wt.println("CAN ${modify[i]}")
        }
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}