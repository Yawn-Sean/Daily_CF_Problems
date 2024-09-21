n, m = MII()
g = [[] for _ in range(n)]
deg = [0] * n
for _ in range(m):
    u, v = GMI()
    deg[u] += 1
    deg[v] += 1
    g[u].append(v)
    g[v].append(u)

@cache
def dfs(x: int) -> int:
    res = 1
    for y in g[x]:
        if y < x:
            res = max(res, dfs(y) + 1)
    return res

ans = 0
for i in range(n):
    ans = max(ans, dfs(i) * deg[i])

print(ans)
