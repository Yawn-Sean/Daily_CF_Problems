"""
计算每条边的贡献，对于两侧子树大小分别为 c1, c2 的边，其计算次数为 c1*comb(c2,2)*2 + c2*comb(c1,2)*2 。在计算期望时，最终贡献还要除以 comb(n,3) 。
以下计算对上式有所化简。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

n = ii()
g = [[] for _ in range(n)]
edges = []
for idx in range(n-1):
    u, v, w = lii()
    u -= 1; v -= 1
    edges.append([u, v, w])
    g[u].append(v)
    g[v].append(u)

size = [1] * n
# 用递归装饰器或改用迭代
def dfs(u, pa):
    for v in g[u]:
        if v == pa: continue
        dfs(v, u)
        size[u] += size[v]
dfs(0, -1)

tot = 0
for u, v, w in edges:
    sz = min(size[u], size[v])
    tot += w * sz * (n-sz)

ans = []
k = n * (n-1) / 6
for _ in range(ii()):
    idx, neww = lii()
    idx -= 1
    u, v, w = edges[idx]
    sz = min(size[u], size[v])
    tot -= (w-neww) * sz * (n-sz)
    ans.append(tot/k)
    edges[idx][2] = neww

print(*ans, sep='\n')