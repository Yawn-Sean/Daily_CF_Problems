# Submission link: https://codeforces.com/problemset/submission/575/325082678#
def main():
    n = II()
    us = []
    vs = []
    ts = []

    path = [[] for _ in range(n)]

    for eid in range(n - 1):
        u, v, t = MII()
        u -= 1
        v -= 1
        
        us.append(u)
        vs.append(v)
        ts.append(t)
        path[u].append(eid)
        path[v].append(eid)

    parent = [-1] * n
    parent_eid = [0] * n
    depth = [0] * n
    que = [0]

    for u in que:
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            if parent[u] != v:
                parent[v] = u
                parent_eid[v] = eid
                depth[v] = depth[u] + 1
                que.append(v)

    nth_parent = [[-1] * n for _ in range(20)]
    nth_parent[0] = parent

    for i in range(1, 20):
        for u in range(n):
            if nth_parent[i - 1][u] != -1:
                nth_parent[i][u] = nth_parent[i - 1][nth_parent[i - 1][u]]

    def lca(u, v):
        if depth[u] < depth[v]:
            u, v = v, u
        
        d = depth[u] - depth[v]
        while d:
            x = d & -d
            
            bit = x.bit_length() - 1
            u = nth_parent[bit][u]
            
            d -= x
        
        if u == v: return u
        
        for i in range(19, -1, -1):
            if nth_parent[i][u] != nth_parent[i][v]:
                u = nth_parent[i][u]
                v = nth_parent[i][v]
        
        return nth_parent[0][u]

    ups = [0] * n
    downs = [0] * n

    k = II()
    nodes = LGMI()

    u = 0
    for i in range(k):
        v = nodes[i]
        
        l = lca(u, v)
        
        ups[u] += 1
        ups[l] -= 1
        downs[v] += 1
        downs[l] -= 1
        u = v

    for i in reversed(que):
        if i > 0:
            ups[parent[i]] += ups[i]
            downs[parent[i]] += downs[i]

    mod = 10 ** 9 + 7
    pw2 = [1] * (k + 1)

    for i in range(1, k + 1):
        pw2[i] = pw2[i - 1] + pw2[i - 1]
        if pw2[i] >= mod: pw2[i] -= mod

    ans = 0
    for i in range(1, n):
        if ts[parent_eid[i]]:
            if i == us[parent_eid[i]]: ans += pw2[downs[i]] - 1
            else: ans += pw2[ups[i]] - 1
            if ans >= mod: ans -= mod

    print(ans)