# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())


tcn = 1
for _tcn_ in range(tcn):
    n = I()
    rects = [LI() for _ in range(n)]
    N = 10 ** 9 + 1
    prefix = [[-N, -N, N, N]]
    for i in range(n):
        x1, x2, x3, x4 = prefix[-1]
        y1, y2, y3, y4 = rects[i]
        z1, z2, z3, z4 = max(x1, y1), max(x2, y2), min(x3, y3), min(x4, y4)
        prefix.append([z1, z2, z3, z4])

    suffix = [[-N, -N, N, N]]
    for i in reversed(range(n)):
        x1, x2, x3, x4 = suffix[-1]
        y1, y2, y3, y4 = rects[i]
        z1, z2, z3, z4 = max(x1, y1), max(x2, y2), min(x3, y3), min(x4, y4)
        suffix.append([z1, z2, z3, z4])

    for i in range(n):
        x1, x2, x3, x4 = prefix[i]
        y1, y2, y3, y4 = suffix[n - 1 - i]
        z1, z2, z3, z4 = max(x1, y1), max(x2, y2), min(x3, y3), min(x4, y4)
        if z1 <= z3 and z2 <= z4:
            print(z1, z2)
            break
