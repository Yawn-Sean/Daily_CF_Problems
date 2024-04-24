private fun solve() {
    // https://codeforces.com/problemset/problem/946/E
    // https://codeforces.com/problemset/submission/946/255201776
    // 感觉像比较经典的贪心，很像next_permutation的逻辑
    val cases = rd.ni()
    val cap = 10
    repeat(cases) {
        val str = rd.ns()
        val nums = str.map { it - '0' }.toIntArray()

        fun out() = wt.println(nums.joinToString(""))
        // 题目保证输入长度为偶数，没有前导零，且输入一定有解
        // 注意要求的数字一定小于输入
        val n = nums.size
        var mask = 0
        for (i in 0 until n) mask = 1 shl nums[i] xor mask
        var tail = 0
        for (i in n - 1 downTo 0) {
            mask = 1 shl nums[i] xor mask
            tail += 1
            val odd = bar(cap) { 1 shl it and mask != 0 }
            val cnt = mask.countOneBits()
            for (j in cap - 1 downTo if (i == 0) 1 else 0) if (j < nums[i]) {
                // 当前位取值一定要小于输入的值
                val rest = if (odd[j]) tail - cnt else tail - cnt - 2
                // 如果该数字之前是奇数个，那么这个位置填j可以消除一个奇数位，剩余需要填tail - cnt
                // 如果该数字之前是偶数个，那么这个位置填j就增加了一个奇数位，剩余需要填tail - cnt - 2
                // 之后的逻辑是相同的
                if (rest >= 0) {
                    nums[i] = j; mask = 1 shl j xor mask
                    // 有多余的位置先往高位填9，然后从大到小填
                    for (iter in i + 1 until n) {
                        if (iter - i <= rest) nums[iter] = 9
                        else {
                            val high = mask.takeHighestOneBit()
                            nums[iter] = high.countTrailingZeroBits()
                            mask = high xor mask
                        }
                    }
                    out(); return@repeat
                }
            }
        }
        wt.println("9".repeat(n - 2))
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}