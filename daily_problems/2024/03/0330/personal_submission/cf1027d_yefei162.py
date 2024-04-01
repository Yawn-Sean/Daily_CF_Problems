# -*- coding : utf-8 -*-
import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n = I()
costs = LI()
edges = LGMI()
deg = [0] * n
g = [[] for _ in range(n)]
for u, v in enumerate(edges):
    deg[v] += 1
    deg[u] += 1
    g[u].append(v)

q = deque(i for i, d in enumerate(deg) if d == 1)
while q:
    x = q.popleft()
    for y in g[x]:
        deg[y] -= 1
        if deg[y] == 1:
            q.append(y)

ans = 0
unvis = [deg[i] == 2 for i in range(n)]
for x in range(n):
    if unvis[x]:
        mi = costs[x]
        while unvis[x]:
            mi = min(mi, costs[x])
            unvis[x] = False
            for y in g[x]:
                if deg[y] == 2:
                    x = y
                    break
        ans += mi

print(ans)
