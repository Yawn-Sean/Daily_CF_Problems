# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
inf = 10 ** 9


def manht(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)


tcn = 1
for _tcn_ in range(tcn):
    n, D = MI()
    A = [0] + LI() + [0]
    coords = [LI() for _ in range(n)]
    g = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            d = manht(*coords[i], *coords[j]) * D
            g[i].append((j, d))
            g[j].append((i, d))

    dist = [inf] * n
    dist[0] = 0
    vis = set()
    for _ in range(n - 1):
        mi = inf
        x = -1
        for i in range(n):
            if i not in vis and dist[i] < mi:
                x = i
                mi = dist[x]
        for y, d in g[x]:
            dist[y] = min(dist[y], dist[x] + d - A[y])
        vis.add(x)
    ans = dist[-1]
    print(ans)
