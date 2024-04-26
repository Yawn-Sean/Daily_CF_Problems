"""
总期望可由每个点期望之和求得。
某个点被控制的期望，就是对于该列 col ， 1~n 的排列 perm 存在 1<=i<=n 满足 col[i]<=perm[i] 的概率。
考虑其相反问题，即对于该列 col ，1~n 的排列 perm 对所有 1<=i<=n 满足 col[i]>perm[i] 的概率。
统计该列数字出现次数。从大到小枚举，对 1<=x<=n ， x 的排列位置方案数为 cnt[x+1]+...+cnt[n+1]-(n-x) ，通过乘法原理计算总方案数即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
lii = lambda: list(map(int, input().split()))

MOD = 998244353

n, m = lii()
mat = [lii() for _ in range(n)]

factn = 1
for x in range(1, n+1):
    factn = factn * x % MOD
ifactn = pow(factn, -1, MOD)

ans = 0
for col in zip(*mat):
    cnt = [0] * (n+2)
    for x in col:
        cnt[x] += 1
    res = 1
    for x in range(n, 0, -1):
        res = res * cnt[x+1] % MOD
        cnt[x] += cnt[x+1] - 1
    ans = (ans + 1 - res * ifactn) % MOD

print(ans)