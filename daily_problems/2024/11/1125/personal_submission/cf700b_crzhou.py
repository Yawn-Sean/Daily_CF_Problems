n, k = MII()
k *= 2

cs = set(LGMI())

g = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = GMI()
    g[u].append(v)
    g[v].append(u)

order = []
st = [(0, -1)]
while st:
    u, fa = st.pop()
    order.append(u)
    for v in g[u]:
        if v == fa:
            continue
        st.append((v, u))

ans = 0
size = [0] * n

for u in order[::-1]:
    res = u in cs
    for v in g[u]:
        res += size[v]
        ans += fmin(k - size[v], size[v])
    size[u] = res

print(ans)
