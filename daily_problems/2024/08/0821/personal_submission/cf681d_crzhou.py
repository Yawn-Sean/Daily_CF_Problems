n, m = MII()
g = [[] for _ in range(n)]
fa = [-1] * n
for _ in range(m):
    u, v = GMI()
    g[u].append(v)
    fa[v] = u
to = LGMI()
tos = set(to)
res = []
tmp = [-1] * n
def bfs(x: int) -> None:
    q = deque([x])
    while q:
        x = q.popleft()
        if x in tos:
            res.append(x)
            tmp[x] = x
        for y in g[x]:
            q.append(y)
            tmp[y] = tmp[x]

for i in range(n):
    if fa[i] == -1:
        bfs(i)
if tmp != to:
    print(-1)
else:
    res.reverse()
    print(len(res))
    print('\n'.join(str(x + 1) for x in res))
