# 快读板子
import random
import sys
from collections import defaultdict
from heapq import heappop, heappush
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

n,m,s,t = RII()
s -= 1
t -= 1
edges = []
g = defaultdict(list)
g_rev = defaultdict(list)
for _ in range(m):
    u,v,w = RII()
    u -= 1
    v -= 1
    edges.append((u,v,w))
    g[u].append((v,w))
    g_rev[v].append((u,w))

dist = [inf]*n
dist[s] = 0
q = [(0,s)]
while q:
    d,u = heappop(q)
    if dist[u] < d:
        continue
    for v,w in g[u]:
        if dist[v] > dist[u] + w:
            dist[v] = dist[u] + w
            heappush(q,(dist[v],v))

dist_rev = [inf]*n
dist_rev[t] = 0
q = [(0,t)]
while q:
    d,u = heappop(q)
    if dist_rev[u] < d:
        continue
    for v,w in g_rev[u]:
        if dist_rev[v] > dist_rev[u] + w:
            dist_rev[v] = dist_rev[u] + w
            heappush(q, (dist_rev[v], v))

mod = random.getrandbits(32)
f = [0]*n
f[s] = 1
for u in sorted(range(n),key = lambda x:dist[x]):
    for v,w in g_rev[u]:
        # v -> u
        if dist[u] == dist[v] + w:
            f[u] = (f[v] + f[u]) % mod

f_rev = [0]*n
f_rev[t] = 1
for u in sorted(range(n),key = lambda x:dist_rev[x]):
    for v,w in g[u]:
        if dist_rev[u] == dist_rev[v] + w:
            f_rev[u] = (f_rev[u] + f_rev[v]) % mod

total_dist = dist[t]
total_method = f[t]
ans = []
for u,v,w in edges:
    if dist[u] + w + dist_rev[v] == total_dist:
        if f[u] * f_rev[v] % mod == total_method:
            ans.append('YES')
        else:
            ans.append('CAN 1' if w > 1 else 'NO')
    elif dist[u] + dist_rev[v] >= total_dist - 1:
        ans.append('NO')
    else:
        ans.append(f'CAN {w - (total_dist - 1 - dist[u] - dist_rev[v])}')

print('\n'.join(ans))