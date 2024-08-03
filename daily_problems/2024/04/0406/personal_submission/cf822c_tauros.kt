private fun solve() {
    // https://codeforces.com/problemset/problem/822/C
    // https://codeforces.com/problemset/submission/822/255171403
    // 按距离分组、按端点排序，分类讨论一下，思维简单但是执行效率不是很高，码量还挺多
    val (n, x) = rd.ni() to rd.ni()
    val vouchers = ar(n) { rd.na(3) }

    val lends = ar(x + 1) { mlo<int>() }
    (0 until n).sortedBy { vouchers[it][0] }.forEach {
        val len = vouchers[it][1] - vouchers[it][0] + 1
        if (len in 1 .. x) lends[len].add(it)
    }
    val rends = ar(x + 1) { mlo<int>() }
    (0 until n).sortedBy { vouchers[it][1] }.forEach {
        val len = vouchers[it][1] - vouchers[it][0] + 1
        if (len in 1 .. x) rends[len].add(it)
    }

    val lsuf = ar(x + 1) {
        buildList {
            for (i in lends[it].indices.reversed())
                add(if (size == 0) vouchers[lends[it][i]][2] else minOf(vouchers[lends[it][i]][2], last()))
        }.reversed()
    }
    val rpre = ar(x + 1) {
        buildList {
            for (i in rends[it].indices)
                add(if (size == 0) vouchers[rends[it][i]][2] else minOf(vouchers[rends[it][i]][2], last()))
        }
    }

    var ans = long.MAX_VALUE
    for (i in 0 until n) {
        val len = vouchers[i][1] - vouchers[i][0] + 1
        val find = x - len
        if (find !in 1 .. x) continue
        val cur = vouchers[i][2].toLong()
        val li = findFirst(lends[find].size) { vouchers[lends[find][it]][0] > vouchers[i][1] }
        if (li < lends[find].size) {
            val res = lsuf[find][li] + cur
            ans = minOf(ans, res)
        }
        val ri = findFirst(rends[find].size) { vouchers[rends[find][it]][1] >= vouchers[i][0] } - 1
        if (ri >= 0) {
            val res = rpre[find][ri] + cur
            ans = minOf(ans, res)
        }
    }
    wt.println(if (ans == long.MAX_VALUE) -1 else ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}