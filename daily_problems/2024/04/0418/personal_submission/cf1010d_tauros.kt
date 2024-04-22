private fun solve() {
    // https://codeforces.com/problemset/problem/1010/D
    // https://codeforces.com/problemset/submission/1010/257188739
    // 注意每个操作互不影响，分操作讨论
    // - AND 都是1的话两个输入都是关键的；都是0的话两个输入都不关键；一个1一个0的话，修改1是不影响输出的所以1那个输入不关键
    // - OR 都是1的话两个输入都不关键；都是0的话两个输入都是关键的；一个1一个0的话，修改0是不影响输出的所以0那个输入不关键
    // - XOR 无论怎样两个输入都关键
    // - NOT 单个输入是关键的
    // 把不关键的输入替换成常量，重新从根dfs下，能访问到的原始输入节点被修改了就会影响输出
    val n = rd.ni()
    val inputs = mlo<int>()
    data class Info(val tp: char, val i0: int, val i1: int)
    val deg = iar(n)
    val dq = dq<int>()
    val topo = Graph(n, n - 1)
    val res = iar(n)
    val nodes = ar(n) {
        val (tp) = rd.ns().toCharArray()
        if (tp in cao('A', 'O', 'X')) {
            val (l, r) = rd.ni() - 1 to rd.ni() - 1
            topo.addEdge(l, it); topo.addEdge(r, it)
            deg[it] += 2
            Info(tp, l, r)
        } else if (tp == 'N') {
            val s = rd.ni() - 1
            topo.addEdge(s, it)
            deg[it] += 1
            Info(tp, s, -1)
        } else {
            inputs.add(it); dq.add(it)
            res[it] = rd.ni()
            Info(tp, res[it], -1)
        }
    }

    val graph = Graph(n, n - 1)
    while (dq.isNotEmpty()) {
        val u = dq.removeFirst()
        val (tp, i0, i1) = nodes[u]
        if (tp == 'N') {
            val r0 = res[i0]
            graph.addEdge(u, i0)
            res[u] = 1 - r0
        } else if (tp == 'A') {
            val (r0, r1) = res[i0] to res[i1]
            if (r0 == r1) {
                if (r0 == 1) {
                    graph.addEdge(u, i0)
                    graph.addEdge(u, i1)
                } else {
                    nodes[u] = Info('C', 0, -1)
                }
            } else {
                nodes[if (r0 == 1) i0 else i1] = Info('C', 1, -1)
                graph.addEdge(u, i0)
                graph.addEdge(u, i1)
            }
            res[u] = r0 and r1
        } else if (tp == 'O') {
            val (r0, r1) = res[i0] to res[i1]
            if (r0 == r1) {
                if (r0 == 0) {
                    graph.addEdge(u, i0)
                    graph.addEdge(u, i1)
                } else {
                    nodes[u] = Info('C', 1, -1)
                }
            } else {
                nodes[if (r0 == 0) i0 else i1] = Info('C', 0, -1)
                graph.addEdge(u, i0)
                graph.addEdge(u, i1)
            }
            res[u] = r0 or r1
        } else if (tp == 'X') {
            val (r0, r1) = res[i0] to res[i1]
            graph.addEdge(u, i0)
            graph.addEdge(u, i1)
            res[u] = r0 xor r1
        }
        topo.each(u) {
            val v = topo.to[it]
            if (--deg[v] == 0) {
                dq.addLast(v)
            }
        }
    }

    val switch = bar(n)
    fun Graph.dfs(u: int) {
        if (nodes[u].tp == 'I') {
            switch[u] = true
            return
        }
        if (nodes[u].tp == 'C') return
        each(u) {
            val v = to[it]
            dfs(v)
        }
    }
    graph.dfs(0)

    val ans = inputs.map { if (switch[it]) 1 - res[0] else res[0] }.toIntArray()
    for (r in ans) wt.print("$r")
    wt.println()
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}