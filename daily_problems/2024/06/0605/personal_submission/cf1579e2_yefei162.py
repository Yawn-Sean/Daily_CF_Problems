# -*- coding: utf-8 -*-
# https://codeforces.com/problemset/submission/1579/264193728
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())

tcn = I()
for _tcn_ in range(tcn):
    n = I()
    A = LI()
    v2i = {v: i for i, v in enumerate(sorted(set(A)))}
    fwt = FenwickTree(n)

    ans = 0
    for i, a in enumerate(A):
        j = v2i[a]
        c1 = fwt.sum(0, j)
        c2 = fwt.sum(j + 1, n)
        ans += min(c1, c2)
        fwt.add(j, 1)
    print(ans)
