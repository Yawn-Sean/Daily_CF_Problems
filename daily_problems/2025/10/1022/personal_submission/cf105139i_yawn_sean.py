# Submission link: https://codeforces.com/gym/105139/submission/344980249
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        path = [[] for _ in range(n + 1)]
        
        for _ in range(n - 1):
            u, v = MII()
            path[u].append(v)
            path[v].append(u)
        
        parent = [0] * (n + 1)
        depth = [0] * (n + 1)
        depth[0] = -1
        
        que = [1]
        for u in que:
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    depth[v] = depth[u] + 1
                    que.append(v)
        
        stk = [1]
        ids = [0] * (n + 1)
        dfs_order = []
        
        while stk:
            u = stk.pop()
            dfs_order.append(u)
            if ids[u] == len(path[u]):
                continue
            
            if path[u][ids[u]] == parent[u]:
                ids[u] += 1
            
            if ids[u] == len(path[u]):
                continue
            stk.append(u)
            stk.append(path[u][ids[u]])
            ids[u] += 1
        
        ls = [3 * n] * (n + 1)
        rs = [0] * (n + 1)
    
        for i in range(len(dfs_order)):
            u = dfs_order[i]
            ls[u] = fmin(ls[u], i)
            rs[u] = fmax(rs[u], i)
            dfs_order[i] += depth[dfs_order[i]] * (n + 1)
        
        st = SparseTable(dfs_order, fmin)
    
        def lca(u, v):
            if ls[u] > ls[v]:
                u, v = v, u
            return st.query(ls[u], ls[v]) % (n + 1)
    
        def dis(u, v):
            return depth[u] + depth[v] - 2 * depth[lca(u, v)]
        
        uf = UnionFind(n + 1)
        top_notes = list(range(n + 1))
    
        tmstamp = [q] * (n + 1)
        
        for tid in range(q):
            u, v = MII()
            l = lca(u, v)
            
            while True:
                u = top_notes[uf.find(u)]
                if depth[u] < depth[l]: break
                tmstamp[u] = tid
                ntop = top_notes[uf.find(parent[u])]
                uf.merge(u, parent[u])
                top_notes[uf.find(u)] = ntop
            
            while True:
                v = top_notes[uf.find(v)]
                if depth[v] < depth[l]: break
                tmstamp[v] = tid
                ntop = top_notes[uf.find(parent[v])]
                uf.merge(v, parent[v])
                top_notes[uf.find(v)] = ntop
        
        tmp = [[] for _ in range(q + 1)]
        for i in range(n + 1):
            tmp[tmstamp[i]].append(i)
        
        ans = [0] * q
        
        us = list(range(n + 1))
        vs = list(range(n + 1))
        ds = [0] * (n + 1)
        
        uf.init()
        
        col = [0] * (n + 1)
        
        cur = 0
        for tid in range(q):
            for u in tmp[tid]:
                col[u] = 1
                for v in path[u]:
                    if col[v] == 1:
                        fu = uf.find(u)
                        fv = uf.find(v)
                        
                        nu, nv, nd = us[fu], vs[fu], ds[fu]
                        if ds[fv] > ds[fu]:
                            nu, nv, nd = us[fv], vs[fv], ds[fv]
                        
                        xu, xv = us[fu], vs[fu]
                        yu, yv = us[fv], vs[fv]
                        
                        for x in [xu, xv]:
                            for y in [yu, yv]:
                                d = dis(x, y)
                                if d > nd:
                                    nu = x
                                    nv = y
                                    nd = d
                        
                        uf.merge(u, v)
                        fu = uf.find(u)
                        
                        us[fu] = nu
                        vs[fu] = nv
                        ds[fu] = nd
                        
                        cur = fmax(cur, nd)
            
            ans[tid] = cur
        
        us = list(range(n + 1))
        vs = list(range(n + 1))
        ds = [0] * (n + 1)
        
        uf.init()
        
        col = [0] * (n + 1)
        
        cur = 0
        for tid in range(q - 1, -1, -1):
            for u in tmp[tid + 1]:
                col[u] = 1
                for v in path[u]:
                    if col[v] == 1:
                        fu = uf.find(u)
                        fv = uf.find(v)
                        
                        nu, nv, nd = us[fu], vs[fu], ds[fu]
                        if ds[fv] > ds[fu]:
                            nu, nv, nd = us[fv], vs[fv], ds[fv]
                        
                        xu, xv = us[fu], vs[fu]
                        yu, yv = us[fv], vs[fv]
                        
                        for x in [xu, xv]:
                            for y in [yu, yv]:
                                d = dis(x, y)
                                if d > nd:
                                    nu = x
                                    nv = y
                                    nd = d
                        
                        uf.merge(u, v)
                        fu = uf.find(u)
                        
                        us[fu] = nu
                        vs[fu] = nv
                        ds[fu] = nd
                        
                        cur = fmax(cur, nd)
            ans[tid] = fmax(ans[tid], cur)
    
        outs.append('\n'.join(str(x + 1) for x in ans))
    
    print('\n'.join(outs))