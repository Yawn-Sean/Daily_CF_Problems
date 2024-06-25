# -*- coding : utf-8 -*-
import sys
from collections import defaultdict
from heapq import heappush, heappop

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
LI = lambda: list(MI())


tcn = 1
for _tcn_ in range(tcn):
    n = I()
    nums = LI()
    h = []
    groups = defaultdict(list)
    vis = set()
    for i, x in enumerate(nums):
        groups[x].append(i)
        if x not in vis:
            heappush(h, x)
            vis.add(x)

    ans = []
    while h:
        x = heappop(h)
        groups[x].sort()
        for i in range(1, len(groups[x]), 2):
            groups[2 * x].append(groups[x][i])
            if x * 2 not in vis:
                heappush(h, x * 2)
                vis.add(x * 2)

        if len(groups[x]) % 2:
            ans.append((x, groups[x][-1]))

    ans.sort(key=lambda x: x[1])
    rets = [x[0] for x in ans]
    print(len(rets))
    print(*rets)
