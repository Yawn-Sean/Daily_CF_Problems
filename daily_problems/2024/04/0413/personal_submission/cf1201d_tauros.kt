private fun solve() {
    // https://codeforces.com/problemset/problem/1201/D
    // https://codeforces.com/problemset/submission/1201/256545311
    // 非常痛苦，每一层只有左右两个关键点，dp[i][0/1]代表第i层结束在左/右两个端点的最小花费
    // 跨层的移动是贪心计算的
    val (n, m, k, q) = rd.na(4)
    val rows = ar(n) { iao(m, -1, it) }
    repeat(k) {
        val (r, c) = rd.ni() - 1 to rd.ni() - 1
        rows[r][0] = minOf(rows[r][0], c)
        rows[r][1] = maxOf(rows[r][1], c)
    }
    val cols = bar(m)
    repeat(q) {
        val col = rd.ni() - 1
        cols[col] = true
    }
    val (left, right) = iar(m) { -1 } to iar(m) { m }
    for (i in 0 until m) left[i] = if (cols[i]) i else if (i == 0) -1 else left[i - 1]
    for (i in m - 1 downTo 0) right[i] = if (cols[i]) i else if (i == m - 1) m else right[i + 1]

    val available = rows.filter { it[0] < m }.toTypedArray()
    val dp = ar(2) { lar(2) }
    var (c0, c1, preRow) = if (available[0][2] == 0) {
        dp[0][0] = rows[0][1].toLong() - rows[0][0] + rows[0][1]
        dp[0][1] = rows[0][1].toLong()
        iao(rows[0][0], rows[0][1], 0)
    } else {
        iao(0, 0, 0)
    }
    val inf = 0x3f3f3f3f3f3f3f3fL
    var cur = 0
    for (i in (if (available[0][2] == 0) 1 else 0) until available.size) {
        val pre = cur; cur = 1 - cur
        dp[cur].fill(inf)
        val (l, r, curRow) = available[i]
        val rowCost = curRow - preRow
        fun go(a: int, b: int): long {
            val (from, to) = minOf(a, b) to maxOf(a, b)
            return if (left[to] >= from) to.toLong() - from
            else minOf(
                if (left[from] >= 0) from.toLong() - left[from] + to - left[from] else inf,
                if (right[to] < m) right[to].toLong() - to + right[to] - from else inf
            )
        }
        // c0 -> r
        val g0r = go(c0, l) + r - l
        dp[cur][1] = minOf(dp[cur][1], dp[pre][0] + g0r + rowCost)
        // c0 -> l
        val g0l = go(c0, r) + r - l
        dp[cur][0] = minOf(dp[cur][0], dp[pre][0] + g0l + rowCost)
        // c1 -> r
        val g1r = go(c1, l) + r - l
        dp[cur][1] = minOf(dp[cur][1], dp[pre][1] + g1r + rowCost)
        // c1 -> l
        val g1l = go(c1, r) + r - l
        dp[cur][0] = minOf(dp[cur][0], dp[pre][1] + g1l + rowCost)
        c0 = l; c1 = r; preRow = curRow
    }
    val ans = dp[cur].min()
    wt.println(ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}