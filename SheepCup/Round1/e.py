def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        queries = []
        
        dsu = UnionFind(n + 1)
        path = [[] for _ in range(n + 1)]
        
        for _ in range(q):
            query = LII()
            if query[0] == 1:
                if dsu.find(query[1]) != dsu.find(query[2]) and dsu.find(query[3]) == dsu.find(query[4]):
                    u, v = query[1], query[2]
                    path[u].append(v)
                    path[v].append(u)
                    dsu.merge(u, v)
            queries.append(tuple(query))
        
        parent = [0] * (n + 1)
        ls = [0] * (n + 1)
        rs = [0] * (n + 1)
        
        depth = [0] * (n + 1)
        tmstamp = 0
        for i in range(1, n + 1):
            if parent[i] == 0:
                stk = [i]
                while stk:
                    u = stk.pop()
                    if u >= 0:
                        ls[u] = tmstamp
                        stk.append(~u)
                        tmstamp += 1
                        for v in path[u]:
                            if parent[u] != v:
                                parent[v] = u
                                depth[v] = depth[u] + 1
                                stk.append(v)
                    else:
                        rs[~u] = tmstamp
        
        nth_parent = [[0] * (n + 1) for _ in range(20)]
        for i in range(n + 1):
            nth_parent[0][i] = parent[i]
        
        for i in range(1, 20):
            for u in range(n + 1):
                nth_parent[i][u] = nth_parent[i - 1][nth_parent[i - 1][u]]

        def lca(u, v):
            if depth[u] > depth[v]:
                u, v = v, u
            
            x = depth[v] - depth[u]
            while x:
                val = x & -x
                v = nth_parent[val.bit_length() - 1][v]
                x -= val
            
            if u == v: return u
            
            for i in range(19, -1, -1):
                if nth_parent[i][u] != nth_parent[i][v]:
                    u = nth_parent[i][u]
                    v = nth_parent[i][v]
            return nth_parent[0][u]

        fen = FenwickTree(n + 10)
        dsu = UnionFind(n + 1)
        
        for query in queries:
            if query[0] == 1:
                if dsu.find(query[1]) != dsu.find(query[2]) and dsu.find(query[3]) == dsu.find(query[4]):
                    u1, v1 = query[1], query[2]
                    dsu.merge(u1, v1)
                    if u1 == parent[v1]: u1, v1 = v1, u1
                    
                    u2, v2 = query[3], query[4]
                    l = lca(u2, v2)
                    d = (fen.sum(ls[u2]) + fen.sum(ls[v2]) - 2 * fen.sum(ls[l]) + query[5]) % mod
                    
                    fen.add(ls[u1], d)
                    fen.add(rs[u1], -d)
            else:
                u = query[1]
                v = query[2]
                l = lca(u, v)
                if dsu.find(u) != dsu.find(v): outs.append(-1)
                else: outs.append((fen.sum(ls[u]) + fen.sum(ls[v]) - 2 * fen.sum(ls[l])) % mod)

    print('\n'.join(map(str, outs)))