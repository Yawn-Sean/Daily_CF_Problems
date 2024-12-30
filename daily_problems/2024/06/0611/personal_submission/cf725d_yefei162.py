# -*- coding: utf-8 -*-
import sys
from heapq import heappop, heappush

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    teams = [LI() for _ in range(n)]
    cur, weight = teams.pop(0)
    teams.sort(key=lambda x: -x[0])

    sl = 0
    h = []
    i = 0
    ans = n
    while i < n:
        while i < n - 1 and teams[i][0] > cur:
            heappush(h, (teams[i][1] - teams[i][0] + 1, teams[i][0]))
            sl += 1
            i += 1

        ans = min(ans, sl + 1)
        if h:
            diff, x = heappop(h)
            if diff <= cur:
                cur = cur - diff
                sl -= 1
            else:
                break
        else:
            ans = min(ans, 1)
            break

    print(ans)
