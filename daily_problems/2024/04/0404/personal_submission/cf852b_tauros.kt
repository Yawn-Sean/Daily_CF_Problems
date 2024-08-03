private fun solve() {
    // https://codeforces.com/problemset/problem/852/B
    // https://codeforces.com/problemset/submission/852/254994235
    // dp一下，一开始以为转移是O(m)的，写着写着发现是O(m^2)的，不得不用矩阵了
    // 需要注意最后一层中间层和最后的出口节点需要合成一层处理一下
    val (n, l, m) = rd.na(3)
    val first = rd.na(n)
    val middle = rd.na(n)
    val last = rd.na(n)

    withMod(1e9.toInt() + 7) {
        fun IntArray.matrix() = run {
            val cnt = iar(m)
            for (c in this) cnt[c % m] += 1
            Matrix(ar(m) { i -> iar(m) { j -> cnt[withMod(m) { i ms j }] } })
        }
        val fm = first.matrix()
        val mm = middle.matrix().pow(l - 2)
        val tail = iar(n) { middle[it] + last[it] }
        val tm = tail.matrix()
        val init = Matrix(ar(m) { i -> if (i == 0) iao(1) else iao(0) })
        val ans = tm * mm * fm * init
        wt.println(ans[0][0])
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}