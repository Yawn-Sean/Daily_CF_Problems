"""
前 i - 1 个点是 DAG，则第 i 个点怎么办？
由于每两个点之间必连一条边，所以拓扑序一定是唯一的
考虑 i 点其在拓扑序中第 j 个位置，则是 DAG 的条件是什么
其他的点编号都比自己小
所以有 j - 1 个点触发了 a / b，有 i - j 个点触发了 1 - a / b
p = a / b
p^(j - 1) * (1 - p)^(i - j)，枚举 j 从 1 到 i，即 j - 1 从 0 到 i - 1
前 i - 1 个点是 DAG 的概率为 dp[i - 1]
p^0 * (1 - p)^(i - 1) + p^1 * (1 - p)^(i - 2) + ... + p^k * (1 - p)^(i - k - 1) + ... + p^(i - 1) * (1 - p)^0
p^0 * (1 - p)^1 + p^1 * (1 - p)^0
p^0 * (1 - p)^2 + p^1 * (1 - p)^1 + p^2 * (1 - p)^0
(1 - p) * (p^0 * (1 - p)^1 + p^1 * (1 - p)^0) + p^2 * (1 - p)^0
利用上面的递推，对于上一个乘积求和，只要乘一个 (1 - p)，再加一个 p^i 就好了
"""
import sys

input = lambda: sys.stdin.readline().strip()

n, a, b = map(int, input().split())
mod = 998244353

p = a * pow(b, -1, mod) % mod
q = ((1 - p) % mod + mod) % mod

contrib = 1
dp = [0 for _ in range(n + 1)]
dp[0] = 1
p_pow = p
for i in range(1, n + 1):
    dp[i] = dp[i - 1] * contrib % mod
    contrib *= q
    contrib += p_pow
    p_pow *= p
    p_pow %= mod
    contrib %= mod
    dp[i] %= mod
print(dp[n])
