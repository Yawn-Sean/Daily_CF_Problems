# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n = I()
segments = [LI() for _ in range(n)]
segments.sort(key=lambda x: (x[0], -x[1]))
L = 0
R = 10 ** 9
for l, r in segments[:-1]:
    L = max(L, l)
    R = min(R, r)

ans = R - L

segments.sort(key=lambda x: (x[1], -x[0]))

L = 0
R = 10 ** 9
for l, r in segments[1:]:
    L = max(L, l)
    R = min(R, r)

ans = max(ans, R - L, 0)
print(ans)
