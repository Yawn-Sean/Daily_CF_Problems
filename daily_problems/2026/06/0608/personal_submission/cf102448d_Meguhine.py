import sys
from math import sqrt
from typing import List

input = lambda: sys.stdin.readline().rstrip()


n, X, Y = map(int, input().split())
xs = [0] * n
ys = [0] * n
rs = [0] * n
ds: List[float] = [0] * n
for i in range(n):
    xs[i], ys[i], rs[i] = map(int, input().split())
    ds[i] = sqrt((X - xs[i])**2 + (Y - ys[i])**2) - rs[i]
idx = sorted(range(n), key=lambda x: ds[x])
ans, cur = 0, 0
for i in idx:
    r, d = rs[i], ds[i]
    if d > cur:
        ans += d - cur
        cur = d
    cur += r
print(f"{ans:.10f}")
