# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = 1
for _tcn_ in range(tcn):
    n, t0 = MI()
    A = LI()
    T = LI()
    low = []
    high = []
    base = 0
    for i in range(n):
        if T[i] < t0:
            low.append((A[i], T[i]))
        elif T[i] > t0:
            high.append((A[i], T[i]))
        else:
            base += A[i]

    x1, y1 = 0, 0
    for a, t in low:
        x1 += a
        y1 += a * t

    x2, y2 = 0, 0
    for a, t in high:
        x2 += a
        y2 += a * t

    if t0 * (x1 + x2) > y1 + y2:
        low.sort(key=lambda x: -x[1])
        for a, t in low:
            x2 += a
            y2 += a * t
            if x2 * t0 > y2:
                x2 -= a
                y2 -= a * t
                xt = (y2 - x2 * t0) / (t0 - t)
                base = base + x2 + xt
                break

    elif t0 * (x1 + x2) < y1 + y2:
        high.sort(key=lambda x: x[1])
        for a, t in high:
            x1 += a
            y1 += a * t
            if x1 * t0 < y1:
                x1 -= a
                y1 -= a * t
                xt = (y1 - x1 * t0) / (t0 - t)
                base = base + x1 + xt
                break

    else:
        base = base + x1 + x2
    print(base)
