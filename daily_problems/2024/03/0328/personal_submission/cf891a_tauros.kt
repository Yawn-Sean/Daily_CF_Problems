fun main(args: Array<String>) {
    // https://codeforces.com/problemset/problem/891/A
    // https://codeforces.com/problemset/submission/891/253610009
    // 应该可以dp吧，我的方法是求每个位置开始最短多少个元素能gcd出1，然后往返一下这部分就全是1了，左右两边剔除1的数字个数加起来，求个最小值，nlognlogM
    val n = readln().toInt()
    val nums = readln().split(" ").map { it.toInt() }.toIntArray()

    val (pre, suf) = iar(n) to iar(n)
    for (i in 0 until n) {
        if (i > 0) pre[i] = pre[i - 1]
        if (nums[i] == 1) pre[i] += 1
    }
    for (i in n - 1 downTo 0) {
        if (i < n - 1) suf[i] = suf[i + 1]
        if (nums[i] == 1) suf[i] += 1
    }
    data class Info(var gcd: int = 0) : SegNonTagNode<Info> {
        override fun update(l: Info, r: Info) {
            gcd = gcd(l.gcd, r.gcd)
        }
    }
    val seg = Seg(n, { ar(it) { Info() } }) { gcd = nums[it] }
    var ans = -1
    for (i in 0 until n) {
        val last = seg.last(i, { gcd }, { gcd -> gcd > 1 }, ::gcd)
        if (last != n) {
            val dist = last - i
            val left = i - (if (i > 0) pre[i - 1] else 0)
            val right = n - 1 - last - (if (last < n - 1) suf[last + 1] else 0)
            val res = left + right + dist + dist
            if (ans == -1 || res < ans) ans = res
        }
    }
    println(ans)
}