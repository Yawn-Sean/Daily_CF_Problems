import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x
'''
https://codeforces.com/problemset/problem/187/C

给定一个包含n个节点和m条边的无向图，每走一条边都需要花费1点能量。有k个特殊点，每经过一个特殊点都可以将当前能量值补充到能量上限。
给定起点s和终点t，求可从点s到达点t的最小能量上限。（保证关键点位置不同且s点必为关键点）

'''
n, m, k = RII()
ks = [0] * (n + 1)
for x in RILIST():
    ks[x] = 1

g = [[] for _ in range(n + 1)]
edges = []
for _ in range(m):
    u, v = RII()
    g[u].append(v)
    g[v].append(u)
    edges.append((u, v))
    
s, t = RII()
ks[t] = 1

# 多源bfs
cur = []
dis = [n] * (n + 1)
froms = [0] * (n + 1)
for i in range(1, n + 1):
    if ks[i]:
        cur.append(i)
        froms[i] = i
        dis[i] = 0

while cur:
    nxt = []
    for u in cur:
        for v in g[u]:
            if dis[v] == n:
                dis[v] = dis[u] + 1
                froms[v] = froms[u]
                nxt.append(v)
    cur = nxt

tmp = [[] for _ in range(n)] # 记录最小代价是(0, n)的边
for i, (u, v) in enumerate(edges):
    c = mx(dis[u], dis[v]) if froms[u] == froms[v] else dis[u] + dis[v] + 1 # 志愿者之间可以直达
    if c < n:
        tmp[c].append((u, v))

uf = UnionFind(n + 1)
for c in range(n):
    for u, v in tmp[c]:
        uf.union(u, v)
        if uf.is_same(s, t):
            exit(print(c))
            
print(-1)