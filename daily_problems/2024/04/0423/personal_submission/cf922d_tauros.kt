private fun solve() {
    // https://codeforces.com/problemset/problem/922/D
    // 不会证，但是感觉可以排序
    // https://codeforces.com/problemset/submission/922/257845181
    val n = rd.ni()
    val strs = ar(n) { rd.ns() }
    fun String.noise() = run {
        var (ans, cnt) = 0L to 0
        for (c in this) {
            if (c == 's') cnt += 1
            else ans += cnt
        }
        ans
    }

    val sorted = (0 until n).sortedWith { a, b ->
        val asc = (strs[a] + strs[b]).noise()
        val desc = (strs[b] + strs[a]).noise()
        -asc.compareTo(desc)
    }
    val total = buildString {
        for (i in sorted) {
            append(strs[i])
        }
    }
    val ans = total.noise()
    wt.println(ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}