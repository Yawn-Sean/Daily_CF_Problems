'''
https://codeforces.com/gym/105012/submission/341622440
'''
# 树形DP，两次遍历

pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x
f = lambda x, y: pmax(x, y) + isqrt(pmin(x, y))

# edges: adjusted to 0-indexed
def solve(n: int, a: list[int], edges: list[list[int]]) -> int:
    mf, md1, md1_i, md2 = [-1] * n, [x for x in a], [-1] * n, [-1] * n
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    stk = [(0, -1)]
    seq = []
    while stk:
        u, p = stk.pop()
        seq.append((u, p))
        for v in g[u]:
            if v != p:
                stk.append((v, u))

    def update(i, j):
        nonlocal a, md1, md1_i, md2
        x = f(md1[j], a[i])
        if x > md1[i]:
            md1[i], md1_i[i], md2[i] = x, j, md1[i]
        elif x > md2[i]:
            md2[i] = x

    for u, p in seq[::-1]:
        for v in g[u]:
            if v != p:
                update(u, v)

    mf[0] = a[0] 
    for u, p in seq:
        s, x, x2 = p, mf[u], -1 
        if md1[u] > x:
            s, mf[u], x, x2 = md1_i[u], md1[u], md1[u], pmax(x, md2[u])
        else:
            x2 = md1[u]
        for v in g[u]:
            if v != p and v == s:
                mf[v] = f(x2, a[v])
            elif v != p:
                mf[v] = f(x, a[v])
    return max(mf)
