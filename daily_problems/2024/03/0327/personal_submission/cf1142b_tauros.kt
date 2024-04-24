private fun solve() {
    // https://codeforces.com/problemset/problem/1142/B
    // https://codeforces.com/problemset/submission/1142/253456929
    // 前后缀分开dp，然后求区间最大值，感觉做复杂了
    val (n, m, q) = rd.na(3)

    val perm = rd.na(n)
    val a = rd.na(m)

    val pos = iar(n + 1)
    for ((i, p) in perm.withIndex()) pos[p] = i + 1

    val suf = buildList {
        val pre = iar(n + 1) { m }
        for ((i, ai) in a.withIndex().reversed()) {
            val p = pos[ai]
            if (p == n) pre[n] = i
            else pre[p] = pre[p + 1]
            add(pre[p])
        }
    }.reversed().toIntArray()

    val closest = buildList {
        val map = (0 until m).groupBy { pos[a[it]] }
        val pre = iar(n + 1) { -1 }
        for ((i, ai) in a.withIndex()) {
            val p = pos[ai]
            if (p == 1) pre[1] = i
            else pre[p] = pre[p - 1]
            if (pre[p] == -1) add(-1)
            else if (p == n) {
                add(pre[p])
            } else {
                val list = map.getOrDefault(p + 1, emptyList())
                val idx = findFirst(list.size) { suf[list[it]] >= pre[p] } - 1
                add(if (idx == -1) -1 else list[idx])
            }
        }
    }.toIntArray()

    data class Info(var max: int = -1) : SegNonTagNode<Info> {
        override fun update(l: Info, r: Info) {
            max = maxOf(l.max, r.max)
        }
    }
    val seg = Seg(m, { ar(it) { Info() } }) { max = closest[it] }

    val ans = iar(q) {
        val (l, r) = rd.ni() - 1 to rd.ni() - 1
        val right = seg.query(l, r + 1, { max }, ::maxOf)
        if (right >= l) 1 else 0
    }
    for (res in ans) wt.print("$res")
    wt.println()
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}