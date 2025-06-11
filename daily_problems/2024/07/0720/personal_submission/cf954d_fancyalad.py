# submission link: https://codeforces.com/contest/954/submission/271500443

import sys
from heapq import *
input = lambda: sys.stdin.readline().strip()

def solve():
    n, m, s, t = map(int, input().split())
    s = s - 1; t = t - 1

    g = [set() for _ in range(n)]
    for _ in range(m):
        x, y = map(int, input().split())
        g[x - 1].add(y - 1)
        g[y - 1].add(x - 1)
    
    # 一开始以为是dij，所以就这么写了，不过解题的思路很有dij的那味儿，又学到了
    h = [(0, s)]
    dis1 = [-1] * n
    dis1[s] = 0
    while h:
        dx, x = heappop(h)
        new_dis = dx + 1
        for y in g[x]:
            if dis1[y] == -1:
                dis1[y] = new_dis
                heappush(h, (new_dis, y))

    h = [(0, t)]
    dis2 = [-1] * n
    dis2[t] = 0
    while h:
        dx, x = heappop(h)
        new_dis = dx + 1
        for y in g[x]:
            if dis2[y] == -1:
                dis2[y] = new_dis
                heappush(h, (new_dis, y))
    # print(dis1, dis2)
    target = dis1[t]
    ans = 0
    for i in range(n):
        for j in range(i):
            if min(dis1[i] + dis2[j], dis1[j] + dis2[i]) + 1 >= target:
                ans += 1

    print(ans - m)
    return

solve()