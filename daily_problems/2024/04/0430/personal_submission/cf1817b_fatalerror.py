"""
首先特殊结点的度数必须 >=4 。
从特殊结点 u 出发 DFS 找环。对 u 的邻居 v ，如果 v 在环上、并且不通过环与 u 直接相连，则可以用边 u-v 取代边 u-*-v 、即将环收缩。最终 u 仅有两个邻居在环上。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

# 较小的递归深度可以直接通过 setrecursionlimit 设置
# 较大的递归深度则需要用到 @bootstrap
sys.setrecursionlimit(2010)

def solve():
    n, m = lii()
    g = [[] for _ in range(n+1)]
    deg = [0] * (n+1)
    for _ in range(m):
        u, v = lii()
        g[u].append(v)
        g[v].append(u)
        deg[u] += 1
        deg[v] += 1

    # 统计特殊点
    specials = [u for u in range(1, n+1) if deg[u] >= 4]
    if not specials:
        print('NO')
        return 

    vertices = []
    vis = [False] * (n+1)
    # DFS 找环，记录环上顶点
    def dfs(u, pa, start):
        vis[u] = True
        vertices.append(u)
        for v in g[u]:
            if v == pa:
                continue
            if v == start:
                return True
            if vis[v]:
                continue
            if dfs(v, u, start):
                return True
        vis[u] = False
        vertices.pop()
        return False

    for u in specials:
        if not dfs(u, 0, u):
            continue
        # adj0, adj1 表示 u 通过环直接相连的邻居
        adj0, adj1 = vertices[1], vertices[-1]
        cycle = set(vertices)
        for v in g[u]:
            if v == adj0 or v == adj1:
                continue
            if v in cycle:
                while vertices[-1] != v:
                    # 删除 u-*-v 之间的顶点
                    w = vertices.pop()
                    cycle.remove(w)
                adj1 = v

        edges = []
        fishtail = 0
        for v in g[u]:
            if v == adj0 or v == adj1:
                continue
            edges.append((u, v))
            fishtail += 1
            if fishtail == 2:
                break

        l = len(vertices)
        for i in range(l):
            edges.append((vertices[i], vertices[(i+1)%l]))

        print('YES')
        print(l+2)
        for edge in edges:
            print(*edge)
        return 

    print('NO')
    return 


for _ in range(ii()):
    solve()