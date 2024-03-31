private fun solve() {
    // https://codeforces.com/problemset/problem/1045/I
    // https://codeforces.com/problemset/submission/1045/253904648
    // 把字符个数的奇偶性表示成一个mask，然后位运算搞搞就好
    val n = rd.ni()
    val strings = ar(n) { rd.ns() }

    fun string.mask(): int {
        var mask = 0
        for (c in this) {
            val idx = c - 'a'
            mask = 1 shl idx xor mask
        }
        return mask
    }
    val cnt = mmo<int, int>().default { 0 }
    var ans = 0L
    for (str in strings) {
        val cur = str.mask()

        ans += cnt[cur]
        for (i in 0 until 26) {
            ans += cnt[1 shl i xor cur]
        }
        cnt[cur] += 1
    }
    wt.println(ans)
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}