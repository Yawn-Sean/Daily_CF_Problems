# -*- coding : utf-8 -*-
import sys
from heapq import heappop, heappush

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
# sys.stdout = open('../../output.txt', 'w')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())


tcn = I()
for _tcn_ in range(tcn):
    n, m = MI()
    nums = LI()
    ops = [[i] + LI() for i in range(m)]

    ops.sort(key=lambda x: (-x[2], -x[0]))

    groups = [0 for _ in range(n)]
    mx = -1
    for i, t, r in ops:
        if i < mx:
            continue
        mx = max(i, mx)
        groups[r - 1] = t
        if i == m - 1:
            break

    h1 = []
    h2 = []
    for i, x in enumerate(nums):
        heappush(h1, (x, i))
        heappush(h2, (-x, i))
    used = set()
    last_tag = 0

    rets = [0] * n
    for i in range(n - 1, -1, -1):
        if groups[i] == 0:
            if last_tag == 0:
                rets[i] = nums[i]
                used.add(i)
            elif last_tag == 1:
                while h2[0][1] in used:
                    heappop(h2)
                x, j = heappop(h2)
                rets[i] = -x
                used.add(j)
            elif last_tag == 2:
                while h1[0][1] in used:
                    heappop(h1)
                x, j = heappop(h1)
                rets[i] = x
                used.add(j)
        else:
            if groups[i] == 1:
                while h2[0][1] in used:
                    heappop(h2)
                x, j = heappop(h2)
                rets[i] = -x
                used.add(j)
                last_tag = 1
            elif groups[i] == 2:
                while h1[0][1] in used:
                    heappop(h1)
                x, j = heappop(h1)
                rets[i] = x
                used.add(j)
                last_tag = 2
    print(*rets)
