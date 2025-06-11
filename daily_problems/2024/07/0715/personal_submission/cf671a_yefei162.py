# -*- coding: utf-8 -*-
import math
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
TI = lambda: tuple(MI())


def get_dist(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))


tcn = 1
for _tcn_ in range(tcn):
    ax, ay, bx, by, tx, ty = MI()
    n = I()
    points = [TI() for _ in range(n)]
    dist1 = [get_dist(x0, y0, ax, ay) for x0, y0 in points]
    dist2 = [get_dist(x0, y0, bx, by) for x0, y0 in points]
    dist3 = [get_dist(x0, y0, tx, ty) for x0, y0 in points]
    tot3 = sum(dist3)
    if n == 1:
        ans = min(dist1[0] + dist3[0], dist2[0] + dist3[0])
        print(ans)
        continue

    diff1 = [(-d3 + d1, i) for i, d3, d1 in zip(range(n), dist3, dist1)]
    diff2 = [(-d3 + d2, i) for i, d3, d2 in zip(range(n), dist3, dist2)]
    diff1.sort()
    diff2.sort()
    ans = min(tot3 + tot3 + diff1[0][0], tot3 + tot3 + diff2[0][0])
    if diff1[0][1] == diff2[0][1]:
        ans = min(ans, tot3 + tot3 + diff1[0][0] + diff2[1][0])
        ans = min(ans, tot3 + tot3 + diff1[1][0] + diff2[0][0])
    else:
        ans = min(ans, tot3 + tot3 + diff1[0][0] + diff2[0][0])
    print(ans)
