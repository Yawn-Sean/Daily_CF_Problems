private fun solve() {
    // https://codeforces.com/problemset/problem/1903/E
    // https://codeforces.com/problemset/submission/1903/256142673
    // 平方不影响奇偶性，每个点自己的奇偶性是可以定义的
    // a b c的三个点的计算结果是 a xor b xor b xor c
    // 因此，出现在中间的点都是无关的，主要是在于选择最开始和最后的点
    // 起点是固定的，争夺最后的点的奇偶性
    // 先手的策略是消耗奇偶性不同的，后手反之
    val cases = rd.ni()
    repeat(cases) {
        val n = rd.ni()
        val start = rd.ni() % 2 xor rd.ni() % 2
        val points = iar(n) { rd.ni() % 2 xor rd.ni() % 2 }

        val (e, o) = (0 until n).partition { points[it] < 1 }
        val cnt = iao(e.size, o.size)
        // n % 2 == 0 && cnt[start] >= n / 2 || n % 2 == 1 && cnt[start] >= n / 2 + 1
        val first = cnt[start] >= (n + 1) / 2
        println(if (first) "First" else "Second")

        val sets = ao(e.toMutableSet(), o.toMutableSet())
        var turn = first
        for (round in 1 .. n) {
            val delete = if (turn) {
                val firstChoice = if (first) start xor 1 else start
                val choose = sets[firstChoice].ifEmpty { sets[firstChoice xor 1] }.first()
                choose.also { println("${it + 1}") }
            } else rd.ni() - 1
            turn = turn xor true
            sets[points[delete]].remove(delete)
        }
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}