# Submission link: https://codeforces.com/gym/105316/submission/351414991
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, q = MII()
        s = I()
        nums = LII()
        
        notes = [0] * (2 * n)
        
        path = [[] for _ in range(n + 1)]
        parent = [-1] * (n + 1)
    
        stk = [0]
        pt = 1
        
        for i in range(2 * n):
            if s[i] == '(':
                parent[pt] = stk[-1]
                path[stk[-1]].append(pt)
                stk.append(pt)
                
                notes[i] = pt
                pt += 1
            else:
                stk.pop()
        
        stk = [0]
        ls = [0] * (n + 1)
        rs = [0] * (n + 1)
        tmstamp = 0
        
        while stk:
            u = stk.pop()
            if u >= 0:
                ls[u] = tmstamp
                tmstamp += 1
                stk.append(~u)
                
                for v in path[u]:
                    stk.append(v)
            else:
                rs[~u] = tmstamp
        
        fen = FenwickTree(n + 1)
        
        depth = [0] * (n + 1)
        
        for i in range(1, n + 1):
            depth[i] = depth[parent[i]] + 1
        
        nth_parent = [[-1] * (n + 1) for _ in range(20)]
        nth_parent[0] = parent
        
        for i in range(19):
            for j in range(n + 1):
                if nth_parent[i][j] != -1:
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
        
        for _ in range(q):
            query = LII()
            
            if query[0] == 1:
                u = notes[query[1] - 1]
                v = notes[query[3] - 1]
                val = query[5]
                l = lca(u, v)
                fen.add(ls[l], val)
            else:
                idx = query[1] - 1
                u = notes[idx]
                outs.append(fen.rsum(ls[u], rs[u] - 1) + nums[idx])
    
    print('\n'.join(map(str, outs)))