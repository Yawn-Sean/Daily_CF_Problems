# -*- coding : utf-8 -*-
import math
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

n, r = MI()
xs = LI()
ans = []
points = []
for x in xs:
    y = r
    for x0, y0 in points:
        if abs(x - x0) <= 2 * r:
            h = math.sqrt(4 * r * r - (x - x0) * (x - x0))
            y = max(y, y0 + h)
    ans.append(y)
    points.append((x, y))
print(*ans)
