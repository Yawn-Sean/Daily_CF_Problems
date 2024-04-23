private fun solve() {
    // https://codeforces.com/problemset/problem/1200/D
    // https://codeforces.com/problemset/submission/1200/257726040
    // 判断该区域内的点是该行全部的点或该列全部的点
    val (n, k) = rd.ni() to rd.ni()
    val grid = ar(n) { rd.ns(n).map { if (it == 'B') 1 else 0 }.toIntArray() }

    val (rowSum, colSum) = ar(n + 1) { iar(n + 1) } to ar(n + 1) { iar(n + 1) }
    var base = 0
    for (i in 0 until n) {
        var (l, r) = n to -1
        for (j in 0 until n) if (grid[i][j] == 1) {
            l = minOf(l, j); r = maxOf(r, j)
        }
        if (l > r) {
            base += 1
            continue
        }
        if (r - l + 1 > k) continue
        for (j in maxOf(0, r - k + 1) .. minOf(n - 1 - k + 1, l)) rowSum[i + 1][j + 1] += 1
    }
    for (j in 0 until n) {
        var (u, d) = n to -1
        for (i in 0 until n) if (grid[i][j] == 1) {
            u = minOf(u, i); d = maxOf(d, i)
        }
        if (u > d) {
            base += 1
            continue
        }
        if (d - u + 1 > k) continue
        for (i in maxOf(0, d - k + 1) .. minOf(n - 1 - k + 1, u)) colSum[i + 1][j + 1] += 1
    }
    for (i in 1 .. n) {
        var (sum1, sum2) = 0 to 0
        for (j in 1 .. n) {
            sum1 += rowSum[i][j]; sum2 += colSum[i][j]
            rowSum[i][j] = rowSum[i - 1][j] + sum1
            colSum[i][j] = colSum[i - 1][j] + sum2
        }
    }
    fun Array<IntArray>.rect(stR: int, edR: int, stC: int, edC: int) =
        this[edR][edC] - this[edR][stC - 1] - this[stR - 1][edC] + this[stR - 1][stC - 1]

    var ans = base
    for (i in 1 .. n - k + 1) for (j in 1 .. n - k + 1) {
        val rowRange = rowSum.rect(i, i + k - 1, j, j)
        val colRange = colSum.rect(i, i, j, j + k - 1)
        val res = base + rowRange + colRange
        ans = maxOf(ans, res)
    }
    wt.println(ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}