import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())

def solve():
    g = [[] for _ in range(n)]
    for i, pi in enumerate(pa, 1):
        g[pi].append(i)
    
    k = n.bit_length() - 1
    mn = [[-1] * n for _ in range(k + 1)]
    dist = [0] * n
    dfn, cnt = [0] * n, 0
    st = [(0, -1)]
    while st:
        x, fa = st.pop()
        dfn[x] = cnt
        mn[0][dfn[x]] = fa
        cnt += 1
        for y in g[x]:
            dist[y] = dist[x] + 1
            st.append((y, x))
    
    for p in range(k):
        for i in range(n - (1 << p)):
            pl, pr = mn[p][i], mn[p][i + (1 << p)]
            mn[p + 1][i] = pl if dfn[pl] < dfn[pr] else pr
    
    def getLCA(u, v):
        if u == v:
            return u
        u, v = dfn[u], dfn[v]
        if u > v:
            u, v = v, u
        p = (v - u).bit_length() - 1
        pl, pr = mn[p][u + 1], mn[p][v - (1 << p) + 1]
        return pl if dfn[pl] < dfn[pr] else pr
        
    def getPath(u, v):
        return dist[u] + dist[v] - dist[getLCA(u, v)] * 2

    for _ in range(m):
        a, b, c = GMI()
        # 不找中點，直接兩兩相加，最後會變成總長度*2(等於一維情況)
        # 去除最小的，為剩下線段交集，重複的最大長度(加回交界點)
        d1, d2, d3 = getPath(a, b), getPath(b, c), getPath(c, a)
        tot = d1 + d2 + d3
        min_d = d1 if d1 < d2 else d2
        min_d = min_d if min_d < d3 else d3
        print((tot - min_d * 2) // 2 + 1)
               
for _ in range(1):
    n, m = MII()
    pa = list(GMI())
    solve()