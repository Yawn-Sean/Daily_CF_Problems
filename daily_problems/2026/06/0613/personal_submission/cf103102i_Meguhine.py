import sys
from array import array

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
if n <= 3:
    exit(print(6 if n == 3 else n))


"""
if n == 6:
    from itertools import permutations
    ans = 0
    for p in permutations(range(1, 7)):
        for i in range(6):
            if p[i - 1] % p[i] > 2:
                break
        else:
            ans += 1
    exit(print(ans))
"""


MOD = 10**9 + 7
dp = array('i', [0] * (n + 1))
dp[n] = 1
for x in range(n - 2, 2, -1):
    o = 1
    if x + 2 <= n:
        o += dp[x + 2]
    for y in range(x * 2, n + 1, x):
        o += dp[y]
        if y + 1 <= n:
            o += dp[y + 1]
            if y + 2 <= n:
                o += dp[y + 2]
    dp[x + 1] = o % MOD

ans = (sum(dp) + 1) * 2 * n
print(ans % MOD)


"""
考虑 3 的后面一定是 1, 2 中的一个
n 的前面一定是 1, 2 中的一个
1, 2 相当于把整个循环数组隔开来了
考虑从 3 到 n 选取了一个子集 S, S (在不考虑循环数组) 的情况下, 有几种合法排列
因为小的元素不可能在大的元素前面 (不然余数 >2)
所以至多只有 **1** 种合法方案 !!!

当然这只是必要条件, 接下来算"链"的方案数, 用 dp 即可. 复杂度是调和级数
假设从大到小枚举到了 x, 现在, 有一个的结尾是 (x+1), 其他的结尾在 (x+2)~(n) 不等
那 x 可以接到哪里?
- x 可以接到任意的 (x+1, i) 的 (x+1) 的后边, 对应的 dp[i] 不变
- x 可以接到任意的 (x+1, i) 的 (i%x) < 3 的后边, dp[x+1] += dp[i]
- 每次记得加上空的 1 (表示全部数全分在一起)

考虑枚举 S 和 S 头尾接的 1, 2, 那就是 dp[3] * 2
因为是循环数组, 需要 * n
"""
