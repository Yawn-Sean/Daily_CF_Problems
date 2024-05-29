# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(GMI())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    P = LGMI()
    ind = [0] * n
    for i, x in enumerate(P):
        ind[x] = i
    ops = []
    for i in range(n):
        x = ind[i]
        if i == x:
            continue
        ind[P[i]], ind[P[x]] = x, i
        P[i], P[x] = P[x], P[i]

        if abs(i - x) * 2 >= n:
            ops.append((i, x))
        else:
            if abs(i - 0) * 2 >= n and abs(n - 1 - x) * 2 >= n:
                ops.append((i, 0))
                ops.append((0, n - 1))
                ops.append((n - 1, x))
                ops.append((n - 1, 0))
                ops.append((0, i))
            elif abs(n - 1 - i) * 2 >= n and abs(x - 0) * 2 >= n:
                ops.append((i, n - 1))
                ops.append((n - 1, 0))
                ops.append((0, x))
                ops.append((0, n - 1))
                ops.append((n - 1, i))
            elif abs(i - 0) * 2 >= n and abs(x - 0) * 2 >= n:
                ops.append((i, 0))
                ops.append((0, x))
                ops.append((0, i))
            elif abs(n - 1 - i) * 2 >= n and abs(n - 1 - x) * 2 >= n:
                ops.append((i, n - 1))
                ops.append((n - 1, x))
                ops.append((n - 1, i))
    print(len(ops))
    for i in range(len(ops)):
        print(ops[i][0] + 1, ops[i][1] + 1)

