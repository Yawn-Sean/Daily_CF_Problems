private fun solve() {
    // https://codeforces.com/problemset/problem/540/E
    // https://codeforces.com/problemset/submission/540/256232112
    // 可以模拟交换，把所有的位置和值都记录下来
    // 然后根据位置排序后，顺序遍历来计算逆序对，值域要离散化一下方便使用树状数组
    // - 考虑每个之前的数字对于当前位置i的贡献
    //   - 首先是树状数组记录下的之前比当前大的数字
    //   - 然后是未产生过交换的数字中比当前大的数字
    // - 还需要考虑当前位置i对于之后数字的贡献
    //   - 这时只用考虑计算之后未交换的位置的贡献即可
    val n = rd.ni()
    val swaps = ar(n) { rd.na(2) }

    val nums = mmo<int, int>()
    for ((a, b) in swaps) {
        val aVal = nums.getOrDefault(a, a)
        val bVal = nums.getOrDefault(b, b)
        nums[b] = aVal; nums[a] = bVal
    }

    val pos = nums.toList().sortedBy { it.first }.toTypedArray()
    val sorted = pos.flatMap { lo(it.first, it.second) }.sorted().distinct().toIntArray()
    val m = sorted.size

    fun IntArray.update(pos: int) = this.bitUpdateWithIndex(pos) { this[it] += 1 }
    fun IntArray.query(pos: int) = this.bitQuery(pos, 0, int::plus)

    val bit = iar(m + 2)
    var ans = 0L
    for (i in pos.indices) {
        val (p, v) = pos[i]
        val j = findFirst(pos.size) { pos[it].first >= v } - 1
        val keep = v - 1 - (j + 1)

        val discrete = findFirst(m) { sorted[it] >= v } + 1
        val gt = bit.query(m + 1) - bit.query(discrete)
//        val pre = if (p > v) (p - 1 - i) - keep else 0
//        val suf = if (p < v) keep - (p - 1 - i) else 0
        val range = abs(keep - (p - 1 - i))

        bit.update(discrete)
        ans += gt + range
    }
    wt.println(ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}