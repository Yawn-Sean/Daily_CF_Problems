private fun solve() {
    // https://codeforces.com/problemset/problem/1592/C
    // https://codeforces.com/problemset/submission/1592/256099100
    // 想了很久，然后会了
    // 异或值要么分成奇数个块要么分成偶数个块
    // 只要异或和为0，那么一定可以分成偶数个块使两个块相等
    // 奇数个块需要讨论下，设总体异或和为sum，考虑a和b两棵子树
    // - a和b不是父子关系，那么a和b都必须等于sum
    // - a和b是父子关系，设a是b的父亲，那么a的异或和为0，b为sum
    // 然后就是只要讨论分成3个块就行，因为5 7 9这些可以把大块再合起来变成3块
    // 也就是奇数块相等的只要存在的话一定可以分成3块相等的
    // 做的时候一个树形dp就可以搞定
    val cases = rd.ni()
    repeat(cases) {
        val (n, k) = rd.ni() to rd.ni()
        val vtx = rd.na(n)
        val graph = Graph(n, (n - 1) * 2)
        repeat(n - 1) {
            val (u, v) = rd.ni() - 1 to rd.ni() - 1
            graph.addEdge(u, v); graph.addEdge(v, u)
        }

        val sum = vtx.fold(0, int::xor)
        var (odd, even) = false to (sum == 0)
        fun Graph.dfs(u: int, fa: int = -1, otherHas: boolean = false): Pair<int, boolean> {
            // otherHas是已经dfs过的所有子树里包含了异或和等于sum的子树
            var (res, has) = vtx[u] to false
            // has是已经处理完的子树里包含了异或和等于sum的子树
            each(u) {
                val v = to[it]
                if (v == fa) return@each
                val (sub, subHas) = dfs(v, u,
                    // 父亲处理过的子树和兄弟子树
                    otherHas or has)
                res = res xor sub
                has = has or subHas
            }
            // 当前树为0，子树有sum
            if (res == 0 && has) odd = true
            // 不在子树中的有sum，自己是sum
            if (otherHas && res == sum) odd = true
            // 返回时把自己的状态处理下
            if (res == sum) has = true
            return res to has
        }
        graph.dfs(0)

        val ans = k >= 2 && even || k >= 3 && odd
        wt.println(if (ans) "YES" else "NO")
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}