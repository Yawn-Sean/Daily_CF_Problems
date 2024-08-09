def kruskal(n, m, k, a):
    fa = list(range(n + 1))
    t = ans = 0
    a.sort(key=lambda e: e.w)
    for i in range(m):
        x = getfa(fa, a[i].u)
        y = getfa(fa, a[i].v)
        if x == y:
            continue
        t = a[i].w
        ans += max(t - k, 0)
        fa[x] = y
    return t, ans

t, ans = kruskal(n, m, k, a)
if t < k:
    ans = inf
    for i in range(m):
        ans = min(ans, abs(a[i].w - k))

results.append(ans)
