# -*- coding: UTF-8 -*-
import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()


MOD = 998244353
N = 10**6 + 5

dp, D = [0] * N, [0] * N
D[2] = 1
for x in range(3, N):
    D[x] = (x - 1) * (D[x - 1] + D[x - 2]) % MOD
    dp[x] = x * (dp[x - 1] + (x - 1) * D[x - 1]) % MOD


t = int(input())
print('\n'.join(
    map(lambda x: str(dp[x]), (int(input()) for _ in range(t)))
))
