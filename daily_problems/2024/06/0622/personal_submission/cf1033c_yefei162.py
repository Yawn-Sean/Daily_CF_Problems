# -*- coding : utf-8 -*-
import sys
from functools import cache

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    A = [0] + LI()
    ans = [False] * (n + 1)


    @cache
    def dfs(i):
        ret = False
        for j in range(i - A[i], 0, -A[i]):
            if A[j] > A[i]:
                ret |= dfs(j)
        for j in range(i + A[i], n + 1, A[i]):
            if A[j] > A[i]:
                ret |= dfs(j)
        return ~ret


    for i in range(1, n + 1):
        ans[i] = dfs(i)

    rets = ['B' if ans[i] else 'A' for i in range(1, n + 1)]

    print(''.join(rets))
