n, m, s, t = MII()
s -= 1
t -= 1
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = GMI()
    g[u].append(v)
    g[v].append(u)

ds = [0] * n
vis = [False] * n
vis[s] = True
st = deque([s])  # bfs
while st:
    u = st.popleft()    # 不是 pop !!!
    for v in g[u]:
        if not vis[v]:
            vis[v] = True
            ds[v] = ds[u] + 1
            st.append(v)

dt = [0] * n
vis = [False] * n
vis[t] = True
st = deque([t])
while st:
    u = st.popleft()
    for v in g[u]:
        if not vis[v]:
            vis[v] = True
            dt[v] = dt[u] + 1
            st.append(v)

min_s = dt[s]
res = 0
for i in range(n):
    for j in range(i + 1, n):
        if min(ds[i] + dt[j], ds[j] + dt[i]) + 1 >= min_s:
            res += 1
print(res - m)
