# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
mod = 998244353

tcn = 1
for _tcn_ in range(tcn):
    n, k = MI()
    if k == 1:
        print(2)
        continue
    dp = [[0 for _ in range(k + 1)] for _ in range(4)]
    # bb bw wb ww
    dp[0][1] = 1
    dp[1][2] = 1
    dp[2][2] = 1
    dp[3][1] = 1
    for i in range(1, n):
        ndp = [[0 for _ in range(k + 1)] for _ in range(4)]
        for j1 in range(4):
            for j2 in range(4):
                for k1 in range(1, k + 1):
                    if j1 == j2 or (j2 == 0 and j1 < 3) or (j2 == 3 and j1 > 0):
                        k2 = k1
                    elif (j1 == 1 and j2 == 2) or (j1 == 2 and j2 == 1):
                        k2 = k1 + 2
                        if k2 > k: continue
                    else:
                        k2 = k1 + 1
                        if k2 > k: continue
                    ndp[j2][k2] += dp[j1][k1]
                    ndp[j2][k2] %= mod
        dp = ndp

    ans = dp[0][k] + dp[1][k] + dp[2][k] + dp[3][k]
    ans %= mod
    print(ans)
