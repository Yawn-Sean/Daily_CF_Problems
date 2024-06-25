# -*- coding: utf-8 -*-
import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())


tcn = I()
for _tcn_ in range(tcn):
    n, m, K = MI()
    X = LI()
    Y = LI()
    input_coords = [TI() for _ in range(K)]

    ans = 0
    coords = sorted(input_coords)
    i = 0
    for j in range(1, len(X)):
        while i < K and X[j - 1] >= coords[i][0]:
            i += 1
        hst = Counter()
        tot = 0
        while i < K and X[j - 1] < coords[i][0] < X[j]:
            hst[coords[i][1]] += 1
            tot += 1
            i += 1

        for k, v in hst.items():
            ans += v * (tot - v)

    coords = sorted(input_coords, key=lambda x: x[1])
    i = 0
    for j in range(1, len(Y)):
        while i < K and Y[j - 1] >= coords[i][1]:
            i += 1
        hst = Counter()
        tot = 0
        while i < K and Y[j - 1] < coords[i][1] < Y[j]:
            hst[coords[i][0]] += 1
            tot += 1
            i += 1

        for k, v in hst.items():
            ans += v * (tot - v)

    print(ans//2)
