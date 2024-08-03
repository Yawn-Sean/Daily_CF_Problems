private fun solve() {
    // https://codeforces.com/problemset/problem/1158/C
    // https://codeforces.com/problemset/submission/1158/255103415
    // i到next[i]之间的所有next[j]应该都小于等于next[i]
    // 构造方法可以贪心的从大的数字开始拿，但是不会证明正确性
    // 可以用构造后再校验的方式判断是否有解，这样复杂度更低一些
    val cases = rd.ni()
    repeat(cases) {
        val n = rd.ni()
        val next = rd.na(n).map { if (it > 0) it - 1 else it }.toIntArray()

        val vis = bar(n)
        val ans = iar(n)
        var top = n
        for (i in 0 until n) if (!vis[i]) {
            val list = buildList {
                var iter = i
                do {
                    vis[iter] = true; add(iter)
                    iter = next[iter]
                } while (iter in 0 until n && !vis[iter])
            }
            val len = list.size
            for (j in 0 until len) ans[list[j]] = top - (len - j)
            top -= len
        }
        top = 0
        for (i in 0 until n) if (!vis[i]) ans[i] = top++

        val (check, stack) = iar(n) { n } to iar(n)
        top = -1
        for (i in 0 until n) {
            while (top >= 0 && ans[i] > ans[stack[top]]) {
                check[stack[top--]] = i
            }
            stack[++top] = i
        }
        if ((0 until n).any { next[it] != -1 && next[it] != check[it] }) {
            wt.println(-1)
        } else {
            for (res in ans) wt.print("${res + 1} ")
            wt.println()
        }
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}