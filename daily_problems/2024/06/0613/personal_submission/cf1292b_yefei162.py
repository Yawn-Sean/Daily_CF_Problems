# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())

tcn = 1
for _tcn_ in range(tcn):
    x0, y0, ax, ay, bx, by = MI()
    xs, ys, t = MI()
    cx, cy = x0, y0

    points = [(cx, cy)]
    for _ in range(64):
        cx = ax * cx + bx
        cy = ay * cy + by
        points.append((cx, cy))
    # print(points)
    n = len(points)

    ans = 0
    for i in range(n):
        x3, y3 = points[i]
        dis = abs(xs - x3) + abs(ys - y3)
        for i1 in range(i, -1, -1):
            for i2 in range(i, n):
                x1, y1 = points[i1]
                x2, y2 = points[i2]
                tot = dis + x2 - x1 + y2 - y1 + min(x3 - x1 + y3 - y1, x2 - x3 + y2 - y3)
                if tot <= t:
                    ans = max(ans, i2 - i1 + 1)

    print(ans)
