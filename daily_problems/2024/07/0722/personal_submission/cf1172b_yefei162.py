# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
mod = 998244353

tcn = 5
for _tcn_ in range(tcn):
    n = I()
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        g[u].append(v)
        g[v].append(u)

    fact = [i for i in range(n + 1)]
    for x in range(2, n + 1):
        fact[x] *= fact[x - 1]
        fact[x] %= mod

    ans = n
    for i in range(n):
        ans *= fact[len(g[i])]
        ans %= mod
    print(ans)
