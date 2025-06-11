# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())

a, b, q = MI()
for _ in range(q):
    l, t, m = MI()
    lo, hi = 0, t * m
    ans = -1
    while lo <= hi:
        mid = (lo + hi) // 2
        tot = (a + (l - 1) * b + a + (l + mid - 1) * b) * (mid + 1) // 2
        mx = a + (l + mid - 1) * b
        if tot <= t * m and mx <= t:
            lo = mid + 1
            ans = mid
        else:
            hi = mid - 1

    if ans >= 0:
        print(l + ans)
    else:
        print(-1)