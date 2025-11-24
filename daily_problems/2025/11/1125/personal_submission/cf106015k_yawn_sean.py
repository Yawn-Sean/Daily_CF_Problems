# Submission link: https://codeforces.com/gym/106015/submission/350481464
def main(): 
    n, m = MII()
    us = []
    vs = []
    ws = []
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)
    
    uf = UnionFind(n)
    st_range = sorted(range(m), key=lambda x: ws[x])
    
    path = [[] for _ in range(n)]
    chosen = [0] * m
    
    for i in st_range:
        if uf.merge(us[i], vs[i]):
            chosen[i] = 1
            path[us[i]].append(ws[i] * n + vs[i])
            path[vs[i]].append(ws[i] * n + us[i])
    
    depth = [0] * n
    to_root = [0] * n
    parent = [-1] * n
    
    que = [0]
    
    for u in que:
        for msk in path[u]:
            w, v = divmod(msk, n)
            if parent[u] != v:
                parent[v] = u
                depth[v] = depth[u] + 1
                to_root[v] = to_root[u] + w
                que.append(v)
    
    nth_parent = [[-1] * n for _ in range(20)]
    nth_parent[0] = parent
    
    for i in range(19):
        for j in range(n):
            if nth_parent[i][j] >= 0:
                nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]]
    
    def lca(u, v):
        if depth[u] > depth[v]:
            u, v = v, u
        
        d = depth[v] - depth[u]
        
        while d:
            x = d & -d
            v = nth_parent[x.bit_length() - 1][v]
            d -= x
        
        if u == v: return u
        
        for i in range(19, -1, -1):
            if nth_parent[i][u] != nth_parent[i][v]:
                u = nth_parent[i][u]
                v = nth_parent[i][v]
        
        return parent[u]
    
    for i in range(m):
        if not chosen[i]:
            u = us[i]
            v = vs[i]
            l = lca(u, v)
            
            if to_root[u] + to_root[v] - 2 * to_root[l] > ws[i]:
                exit(print('NO'))
    
    print('YES')