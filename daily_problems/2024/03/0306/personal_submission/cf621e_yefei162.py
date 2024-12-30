# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())
mod = 1000000007

tcn = 1
for _tcn_ in range(tcn):
    n, m, k, x = MI()
    nums = LI()
    dp = [[0 for _ in range(x)] for _ in range(32)]
    for j in range(n):
        dp[0][nums[j] % x] += 1

    for i in range(31):
        for j1 in range(x):
            for j2 in range(x):
                j3 = (j1 * pow(10, pow(2, i), x) + j2) % x
                dp[i + 1][j3] += dp[i][j1] * dp[i][j2] % mod
                dp[i + 1][j3] %= mod

    f = [0] * x
    first = True
    left = 0
    for i in range(31):
        if m >> i & 1:
            if first:
                f = dp[i].copy()
                first = False
                left += 1 << i
            else:
                g = [0] * x
                for j1 in range(x):
                    for j2 in range(x):
                        j3 = (j1 * pow(10, left, x) + j2) % x
                        g[j3] += dp[i][j1] * f[j2]
                        g[j3] %= mod
                f = g
                left += 1 << i
    ans = f[k]
    print(ans)
