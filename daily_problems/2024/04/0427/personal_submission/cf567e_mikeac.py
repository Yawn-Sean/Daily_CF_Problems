import math
import random
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

def dijkstra(g: list, start: int) -> list:
    dist = [math.inf] * len(g)
    dist[start] = 0
    h = [(0, start)]
    while h:
        d, x = heappop(h)
        if d > dist[x]:
            continue
        for y, wt in g[x]:
            new_d = dist[x] + wt
            if new_d < dist[y]:
                dist[y] = new_d
                heappush(h, (new_d, y))
    return dist

def solve() -> None:
    n, m, s, t = mint()
    s -= 1
    t -= 1
    edges = []
    g = [[] for _ in range(n)]
    ng = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = mint()
        u -= 1
        v -= 1
        edges.append((u, v, w))
        g[u].append((v, w))
        ng[v].append((u, w))
    
    dist1 = dijkstra(g, s)
    dist2 = dijkstra(ng, t)

    MOD = random.getrandbits(32)

    dp1 = [0] * n
    dp1[s] = 1

    for u in sorted(range(n), key = lambda x: dist1[x]):
        for v, w in ng[u]:
            if dist1[u] == dist1[v] + w:
                dp1[u] = (dp1[u] + dp1[v]) % MOD

    dp2 = [0] * n
    dp2[t] = 1

    for u in sorted(range(n), key=lambda x: dist2[x]):
        for v, w in g[u]:
            if dist2[u] == dist2[v] + w:
                dp2[u] = (dp2[u] + dp2[v]) % MOD
    
    for u, v, w in edges:
        if dist1[u] + w + dist2[v] == dist1[t]:
            if dp1[u] * dp2[v] % MOD == dp1[t]:
                print("YES")
            else:
                print("CAN 1" if w > 1 else "NO")
        elif dist1[u] + dist2[v] >= dist1[t] - 1:
            print('NO')
        else:
            res = w - dist1[t] + 1 + dist1[u] + dist2[v]
            print("CAN", res)


solve()
