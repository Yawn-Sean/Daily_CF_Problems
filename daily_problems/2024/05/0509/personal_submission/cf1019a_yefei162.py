# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('./../input.txt', 'r')
MI = lambda: map(int, input().split())


tcn = 1
for _tcn_ in range(tcn):
    n, m = MI()
    groups = [[] for _ in range(m)]
    for i in range(n):
        j, c = MI()
        groups[j - 1].append(c)
    for group in groups:
        group.sort()

    ans = 1 << 64
    for k in range(n // 2, -1, -1):
        tot = len(groups[0])
        tmp = []
        cost = 0
        for i in range(1, m):
            if len(groups[i]) <= k:
                tmp.extend(groups[i])
            else:
                n1 = len(groups[i])
                tot += n1 - k
                cost += sum(groups[i][:n1 - k])
                tmp.extend(groups[i][n1 - k:])

        if tot > k:
            ans = min(ans, cost)
        else:
            tmp.sort()
            ans = min(ans, cost + sum(tmp[:k + 1 - tot]))
    print(ans)
