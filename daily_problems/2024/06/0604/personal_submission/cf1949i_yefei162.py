# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())
YN = lambda x: print('YES' if x else 'NO')


tcn = 1
for _tcn_ in range(tcn):
    n = I()
    disks = [LI() for _ in range(n)]
    g = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            dx = disks[i][0] - disks[j][0]
            dy = disks[i][1] - disks[j][1]
            r = disks[i][2] + disks[j][2]
            if dx * dx + dy * dy == r * r:
                g[i].append(j)
                g[j].append(i)

    colors = [0] * n
    color = 0
    ans = False
    for i in range(n):
        if colors[i] != 0:
            continue
        color += 1
        can_bi = True
        q = [i]
        while q:
            x = q.pop()
            if colors[x] == 0:
                colors[x] = color
            for y in g[x]:
                if colors[y] == 0:
                    colors[y] = -colors[x]
                    q.append(y)
                else:
                    if colors[y] == -colors[x]:
                        continue
                    else:
                        can_bi = False
                        break
        if can_bi:
            if colors.count(color) != colors.count(-color):
                ans = True
    YN(ans)
