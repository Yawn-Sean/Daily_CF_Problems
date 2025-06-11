# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
YN = lambda x: print('YES' if x else 'NO')


tcn = I()
for _tcn_ in range(tcn):
    x1, x2 = MI()
    x = x1 * x2
    y0 = int(x ** (1 / 3))
    ans = False
    for y in (y0 - 1, y0, y0 + 1):
        if y * y * y == x:
            if x1 % y == 0 and x2 % y == 0:
                ans = True
            break
    YN(ans)
