private fun solve() {
    // https://codeforces.com/problemset/problem/226/B
    // https://codeforces.com/problemset/submission/226/255602057
    // 猜一个贪心试试，越小的数应该分配越多的贡献次数
    // 然后k可能会重复，重要的是会有多次1出现，缓存一下即可
    val n = rd.ni()
    val nums = rd.na(n).sortedArray()

    val sums = nums.runningFold(0L, long::plus).toLongArray()
    val q = rd.ni()
    val ans = lar(n) {
        val k = it + 1
        var res = 0L
        var (iter, cnt) = n - 1 to 1
        var range = k.toLong()
        while (iter > 0) {
            val end = maxOf(0, iter - range).toInt()
            val sum = sums[iter] - sums[end]
            res += sum * cnt
            iter = end; cnt += 1; range *= k
        }
        res
    }
    repeat(q) {
        val k = minOf(rd.ni(), n)
        wt.print("${ans[k - 1]} ")
    }
    wt.println()
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}