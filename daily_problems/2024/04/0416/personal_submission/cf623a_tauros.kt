private fun solve() {
    // https://codeforces.com/problemset/problem/623/A
    // https://codeforces.com/problemset/submission/623/256906649
    // https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/04/0416/solution/cf623a.md
    // 学的羊解
    val (n, m) = rd.ni() to rd.ni()
    val graph = ar(n) { bar(n) }
    repeat(m) {
        val (u, v) = rd.ni() - 1 to rd.ni() - 1
        graph[u][v] = true; graph[v][u] = true
    }

    val reversedGraph = ar(n) { bar(n) }
    val dsu = DSU(n)
    for (i in 0 until n) for (j in 0 until n) if (i != j) {
        reversedGraph[i][j] = !graph[i][j]
        if (reversedGraph[i][j]) dsu.merge(i, j)
    }

    val ans = iar(n) { -1 }
    fun dfs(u: int, c: int = 0): boolean {
        if (ans[u] != -1 && ans[u] != c) return false
        if (ans[u] == c) return true
        ans[u] = c
        for (v in 0 until n) if (reversedGraph[u][v]) {
            if (!dfs(v, 2 - c)) return false
        }
        return true
    }
    var success = true
    for (i in 0 until n) if (ans[i] == -1) {
        if (dsu.size(i) == 1) ans[i] = 1
        else {
            if (!dfs(i)) {
                success = false; break
            }
        }
    }
    if (!success) {
        wt.println("No")
        return
    }
    out@ for (i in 0 until n) for (j in 0 until n) if (i != j) {
        if ((abs(ans[i] - ans[j]) == 2) != reversedGraph[i][j]) {
            success = false; break@out
        }
    }
    if (!success) {
        wt.println("No")
        return
    }
    wt.println("Yes")
    for (res in ans) wt.print('a' + res)
    wt.println()
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}