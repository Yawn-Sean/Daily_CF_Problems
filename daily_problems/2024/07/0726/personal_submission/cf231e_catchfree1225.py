import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
MOD = int(1e9 + 7)

class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
    
    def find(self, u):
        while u != self.p[u]:
            self.p[u] = self.p[self.p[u]]
            u = self.p[u]
        return u

def solve():
    uf = UnionFind(n)
    g = [[] for _ in range(n)] # 組成無向樹
    extra_edges = [] # 成環的邊
    for _ in range(m):
        u, v = GMI()
        pu, pv = uf.find(u), uf.find(v)
        if pu != pv:
            uf.p[pv] = pu
            g[u].append(v)
            g[v].append(u)
        else:
            extra_edges.append((u, v))
    
    k = n.bit_length() - 1
    mn = [[-1] * n for _ in range(k + 1)] # 範圍內最小dfn之父節點
    dfn = [0] * n
    st, order = [(0, -1)], [] 
    while st:
        x, fa = st.pop()
        dfn[x] = len(order)
        mn[0][dfn[x]] = fa
        order.append((x, fa))
        for y in g[x]:
            if y != fa:
                st.append((y, x))
    
    for p in range(k):
        for i in range(n - (1 << p)):
            pl, pr = mn[p][i], mn[p][i + (1 << p)]
            mn[p + 1][i] = pl if dfn[pl] < dfn[pr] else pr
    
    def getLCA(u, v):
        if u == v: # 因為紀錄的是父節點，得特判一樣的
            return u
        u, v = dfn[u], dfn[v]
        if u > v:
            u, v = v, u
        p = (v - u).bit_length() - 1
        pl, pr = mn[p][u + 1], mn[p][v - (1 << p) + 1]
        return pl if dfn[pl] < dfn[pr] else pr

    cnt = [0] * n # 紀錄環的編號，再轉成前綴和
    for i, (u, v) in enumerate(extra_edges, 1):
        lca = getLCA(u, v)
        lca_fa = mn[0][dfn[lca]]
        cnt[u] += i
        cnt[v] += i
        cnt[lca] -= i
        if lca_fa != -1:
            cnt[lca_fa] -= i
    for x, fa in reversed(order):
        if fa != -1:
            cnt[fa] += cnt[x]
    
    sum_cnt = [0] * n
    sum_cnt[0] = 1 if cnt[0] else 0
    for x, fa in order:
        for y in g[x]:
            if y != fa:
                sum_cnt[y] = sum_cnt[x] + (cnt[y] and cnt[x] != cnt[y])
    
    for _ in range(int(input())):
        u, v = GMI()
        lca = getLCA(u, v)
        ans = sum_cnt[u] + sum_cnt[v] - sum_cnt[lca] * 2 + (cnt[lca] != 0)
        print(pow(2, ans, MOD))

for _ in range(1):
    n, m = MII()
    solve()