# -*- coding: utf-8 -*-
# https://codeforces.com/problemset/submission/1133/264084127
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')


tcn = 1
for _tcn_ in range(tcn):
    n, m, D = MI()
    edges = [LGMI() for _ in range(m)]

    dsu1 = DSU(n)
    dsu2 = DSU(n)
    deg = 0
    for x, y in edges:
        dsu1.merge(x, y)
        if x == 0 or y == 0:
            deg += 1
        else:
            dsu2.merge(x, y)

    groups1 = dsu1.groups()
    groups2 = dsu2.groups()

    if deg < D:
        YN(False)
    else:
        if len(groups1) == 1 and len(groups2) - 1 <= D:
            YN(True)
            vis = [0] * len(groups2)
            v2g = [0] * n
            for i, group in enumerate(groups2):
                for x in group:
                    v2g[x] = i
            ans = []

            ee = []
            g = [[] for _ in range(n)]
            for x, y in edges:
                g[x].append(y)
                g[y].append(x)
                if x == 0 or y == 0:
                    ee.append((x, y))

            dsu3 = DSU(n)
            d = D
            for x, y in ee:
                if y == 0:
                    x, y = y, x

                if not vis[v2g[y]]:
                    ans.append((x, y))
                    vis[v2g[y]] = 1
                    dsu3.merge(x, y)
                    d -= 1
            for x, y in ee:
                if d == 0:
                    break
                if dsu3.same(x, y):
                    continue
                else:
                    ans.append((x, y))
                    dsu3.merge(x, y)
                    d -= 1

            for x, y in edges:
                if dsu3.same(x, y) or x == 0 or y == 0:
                    continue
                else:
                    ans.append((x, y))
                    dsu3.merge(x, y)
            for x, y in ans:
                print(x+1, y + 1)

        else:
            YN(False)
