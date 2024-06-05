from sys import stdin
def tangent(c1, c2):
    x1, y1, r1 = c1
    x2, y2, r2 = c2
    dis = ((x2 - x1)**2 + (y2 - y1)**2)**.5
    return dis == r1 + r2
n = int(input())
c = [tuple(map(int, input().split())) for _ in range(n)]
adj = [[] for _ in range(n)]
for i in range(n):
    for j in range(i+1, n):
        if tangent(c[i], c[j]):
            adj[i] += [j]
            adj[j] += [i]
def bfs(u):
    vis = [-1]*n
    vis[u] = 0
    st = [(u, 0)]
    ct = 0
    for u, col in st:
        ct += 1
        for v in adj[u]:
            if vis[v] == col^1: continue
            if vis[v] == col: return False
            vis[v] = col^1
            st += [(v, col^1)]
    return vis.count(1) != vis.count(0)
for i in range(n):
    if bfs(i):
        print('YES')
        break
else:
    print('NO')
