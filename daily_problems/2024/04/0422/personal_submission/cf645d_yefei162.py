# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n, m = MI()
edges = [LGMI() for _ in range(m)]
g = [[] for _ in range(n)]
deg = [0] * n
for i in range(m):
    u, v = edges[i]
    g[u].append(v)
    deg[v] += 1
q = []
for i, d in enumerate(deg):
    if d == 0:
        q.append(i)
if len(q) > 1:
    exit(print(-1))

topo = []
while q:
    x = q.pop()
    topo.append(x)
    for y in g[x]:
        deg[y] -= 1
        if deg[y] == 0:
            q.append(y)
    if len(q) > 1:
        exit(print(-1))

st = set()
for i in range(1, n):
    u, v = topo[i - 1], topo[i]
    st.add((u, v))

for i in range(m):
    if (edges[i][0], edges[i][1]) in st:
        ans = i + 1
print(ans)