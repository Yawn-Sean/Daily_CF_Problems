n, m, k = MII()

g = [[] for _ in range(n)]
for i in range(m):
    u, v = GMI()
    g[u].append((v, i))
    g[v].append((u, i))

q = deque([0])
vis = [False] * n
vis[0] = True
cen = []
while q:
    tmp = len(q)
    cur = []
    for _ in range(tmp):
        x = q.popleft()
        cur.append(x)
        for y, _ in g[x]:
            if not vis[y]:
                vis[y] = True
                q.append(y)
    cen.append(cur)

a = []

for i in range(1, len(cen)):
    pre = set(cen[i - 1])
    for x in cen[i]:
        tmp = []
        for y, i in g[x]:
            if y in pre:
                tmp.append(i)
        if tmp:
            a.append(tmp)

ans = []
use = [0] * n
for _ in range(k):
    res = ["0"] * m
    for i in range(n - 1):
        res[a[i][use[i]]] = "1"
    ans.append("".join(res))
    if len(ans) == k:
        break
    for i in range(n - 1):
        if use[i] + 1 < len(a[i]):
            use[i] += 1
            break
        else:
            use[i] = 0
    else:
        break

print(len(ans))
print('\n'.join(ans))
