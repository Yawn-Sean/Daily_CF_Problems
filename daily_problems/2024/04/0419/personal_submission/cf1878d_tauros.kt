private fun solve() {
    // https://codeforces.com/problemset/problem/1878/D
    // https://codeforces.com/problemset/submission/1878/257274730
    // 题意就是告诉你l和r数组形成了不相交的区间，并且可以完全拼接成长度为n的区间
    // 然后x只用确定是哪一段，一定可以属于一个唯一的区间
    // 操作就是找x关于l r中点对称的y，翻转x y区间
    // 线段树做很好做，也可以离线处理下从离中点远到近用类似静态区间差分的方式On处理
    val cases = rd.ni()
    repeat(cases) {
        val (n, k) = rd.ni() to rd.ni()
        val str = rd.ns(n)
        val (left, right) = rd.na(k).map { it - 1 }.toIntArray() to rd.na(k).map { it - 1 }.toIntArray()

        val bel = iar(n)
        for (i in 0 until k) for (j in left[i] .. right[i]) bel[j] = i

        val q = rd.ni()
        val flip = bar(n)
        repeat(q) {
            val x = rd.ni() - 1
            val i = bel[x]
            val mid = left[i] + right[i] shr 1
            val end = if (x <= mid) x else left[i] + right[i] - x
            flip[end] = !flip[end]
        }

        for (i in 0 until k) {
            val mid = left[i] + right[i] shr 1
            var res = false
            for (j in left[i] .. mid) {
                res = res xor flip[j]
                if (res) str.swap(j, left[i] + right[i] - j)
            }
        }
        wt.println(String(str))
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}