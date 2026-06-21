# Submission link: https://codeforces.com/gym/106592/submission/379671389
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, xor_op = MII()
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
        
        ans = 0
        uf = UnionFind(n)
        
        path = [[] for _ in range(n)]
        
        for i in sorted(range(m), key=lambda x: ws[x]):
            if uf.merge(us[i], vs[i]):
                u, v, w = us[i], vs[i], ws[i]
                ans += w
                path[u].append(w * n + v)
                path[v].append(w * n + u)
        
        nth_parent = [[-1] * n for _ in range(18)]
        nth_edge = [[0] * n for _ in range(18)]
        depth = [0] * n
        
        que = [0]
        for u in que:
            for msk in path[u]:
                w, v = divmod(msk, n)
                if nth_parent[0][u] != v:
                    nth_parent[0][v] = u
                    nth_edge[0][v] = w
                    depth[v] = depth[u] + 1
                    que.append(v)
        
        for i in range(17):
            for u in range(n):
                if nth_parent[i][u] != -1:
                    nth_parent[i + 1][u] = nth_parent[i][nth_parent[i][u]]
                    nth_edge[i + 1][u] = fmax(nth_edge[i][u], nth_edge[i][nth_parent[i][u]])
        
        diff = xor_op if m == n - 1 else 0
        
        for i in range(m):
            u, v, w = us[i], vs[i], ws[i]
            
            if depth[u] > depth[v]:
                u, v = v, u
            
            cur = 0
            d = depth[v] - depth[u]
            
            while d:
                x = d & -d
                bit = x.bit_length() - 1
                cur = fmax(cur, nth_edge[bit][v])
                v = nth_parent[bit][v]
                d -= x
            
            if u != v:
                for i in range(17, -1, -1):
                    if nth_parent[i][u] != nth_parent[i][v]:
                        cur = fmax(cur, nth_edge[i][u])
                        u = nth_parent[i][u]
                        cur = fmax(cur, nth_edge[i][v])
                        v = nth_parent[i][v]
                
                cur = fmax(cur, nth_edge[0][u])
                cur = fmax(cur, nth_edge[0][v])
            
            diff = fmin(diff, (w ^ xor_op) - cur)
        
        outs.append(ans + diff)
    
    print('\n'.join(map(str, outs)))