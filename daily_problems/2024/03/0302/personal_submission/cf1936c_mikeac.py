import math
import sys
from heapq import *

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n, m = mint()
    cost = ints()
    g = [[] for _ in range(n * (m + 1))]
    attr = []
    for i in range(n):
        attr.append(ints())
        
        for j in range(m):
            atti = (j + 1) * n + i
            g[i].append((atti, cost[i]))
            g[atti].append((i, 0))

    idx = list(range(n))
    for j in range(m):
        idx.sort(key = lambda x: attr[x][j])
        for i in range(1, n):
            x = (j + 1) * n + idx[i - 1]
            y = (j + 1) * n + idx[i]
            g[x].append((y, attr[idx[i]][j] - attr[idx[i - 1]][j]))
            g[y].append((x, 0))

    dis = [math.inf] * (n * (m + 1))
    dis[n - 1] = 0
    h = [(0, n - 1)]
    while h:
        d, x = heappop(h)
        if d > dis[x]:
            continue
        for y, w in g[x]:
            new_d = d + w
            if new_d < dis[y]:
                dis[y] = new_d
                heappush(h, (new_d, y))
    print(dis[0])


for _ in range(int(input())):
    solve()
