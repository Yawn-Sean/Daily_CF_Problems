# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = I()
for _tcn_ in range(tcn):
    n, k = MI()
    A = LI()
    edges = [LGMI() for _ in range(n - 1)]
    xor = 0
    for a in A:
        xor ^= a
    # print(xor)
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    if xor == 0:
        YN(True)
        continue

    dfs = []
    stk = [(0, -1)]
    fas = [-1] * n
    while stk:
        x, fa = stk.pop()
        fas[x] = fa
        dfs.append(x)
        for y in g[x]:
            if y != fa:
                stk.append((y, x))

    dp = [0] * n
    for x in dfs[::-1]:
        dp[x] ^= A[x]
        fa = fas[x]
        if fa >= 0:
            dp[fa] ^= dp[x]

    f = [0] * n
    for x in dfs[::-1]:
        if dp[x] == xor:
            f[x] = 1
        if dp[x] == 0 and f[x] > 0:
            f[0] = 2
            break

        fa = fas[x]
        if fa >= 0:
            f[fa] += f[x]
            if f[fa] >= 2:
                f[0] = 2
                break

    YN(f[0] >= 2 and k >= 3)


