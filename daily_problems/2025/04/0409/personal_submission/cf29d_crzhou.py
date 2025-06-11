n = II()
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = MII()
    g[u].append(v)
    g[v].append(u)

ks = LII()

fa = [-1] * (n + 1)

def dfs(u: int, f: int) -> None:
    fa[u] = f
    for v in g[u]:
        if v != f:
            dfs(v, u)
dfs(1, 0)

newg = [[] for _ in range(n + 1)]
vis = [0] * (n + 1)

for k in ks:
    while not vis[k] and k != 1:
        vis[k] = 1
        f = fa[k]
        newg[f].append(k)
        k = f
    
s = set(ks)
ans = []
def dfs1(u: int, f: int) -> int:
    ans.append(u)
    for v in newg[u]:
        if v != f:
            dfs1(v, u)
        if u not in s:
            ans.append(u)
dfs1(1, 0)
newks = []
for x in ans:
    if x in s:
        newks.append(x)

if newks == ks:
    print(' '.join(map(str, ans)))
else:
    print(-1)
