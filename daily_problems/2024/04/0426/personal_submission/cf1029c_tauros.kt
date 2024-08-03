private fun solve() {
    // https://codeforces.com/problemset/problem/1029/C
    // https://codeforces.com/problemset/submission/1029/258254542
    // 我日想了好久没明白，学了羊解
    // 去掉一个区间后，剩下的区间的交就是答案
    // 而剩下的区间的交等于剩下区间的左端点最大值与右端点最小值围成的区间
    // 因此枚举每一个删除的区间，求区间序列的 前缀左端点最大值右端点最小值 和 后缀左端点最大值和右端点最小值 即可
    val n = rd.ni()
    val ranges = ar(n) { rd.na(2) }

    val inf = 0x3f3f3f3f
    val (preMaxL, preMinR) = iar(n + 1) to iar(n + 1) { inf }
    val (sufMaxL, sufMinR) = iar(n + 2) to iar(n + 2) { inf }
    for (i in 1 .. n) {
        val (l, r) = ranges[i - 1]
        preMaxL[i] = maxOf(preMaxL[i - 1], l)
        preMinR[i] = minOf(preMinR[i - 1], r)
    }
    for (i in n downTo 1) {
        val (l, r) = ranges[i - 1]
        sufMaxL[i] = maxOf(sufMaxL[i + 1], l)
        sufMinR[i] = minOf(sufMinR[i + 1], r)
    }

    var ans = 0L
    for (i in 1 .. n) {
        val l = maxOf(preMaxL[i - 1], sufMaxL[i + 1])
        val r = minOf(preMinR[i - 1], sufMinR[i + 1])
        ans = maxOf(ans, r - l.toLong())
    }
    wt.println(ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}