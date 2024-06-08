# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
mod = 1000000007

tcn = 1
for _tcn_ in range(tcn):
    n, m, k, r, c = MI()
    x1, y1, x2, y2 = MI()
    if x1 == x2 and y1 == y2:
        ans = pow(k, n * m, mod)
    else:
        ans = pow(k, n * m - r * c, mod)
    print(ans)
