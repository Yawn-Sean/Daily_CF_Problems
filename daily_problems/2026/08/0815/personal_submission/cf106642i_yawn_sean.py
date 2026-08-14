# Submission link: https://codeforces.com/gym/106642/submission/387003977
def main():
    n, q = MII()
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    parent = [-1] * n
    depth = [0] * n
    stk = [0]
    
    ls = [0] * n
    rs = [0] * n
    
    tmstamp = 0
    
    while stk:
        u = stk.pop()
        if u >= 0:
            ls[u] = tmstamp
            tmstamp += 1
            stk.append(~u)
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    depth[v] = depth[u] + 1
                    stk.append(v)
        else:
            rs[~u] = tmstamp
    
    nth_parent = [[-1] * n for _ in range(20)]
    nth_parent[0] = parent
    
    for i in range(19):
        for j in range(n):
            if nth_parent[i][j] != -1:
                nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]]
    
    def merge(x, y):
        x1, x2 = divmod(x, n + 1)
        y1, y2 = divmod(y, n + 1)
        if x1 < y1: return x
        if x1 > y1: return y
        return x1 * (n + 1) + (x2 + y2)
    
    def mapping(x, y):
        return x * (n + 1) + y
    
    def composition(x, y):
        return x + y
    
    def lca(u, v):
        if depth[u] > depth[v]:
            u, v = v, u
        
        d = depth[v] - depth[u]
        while d:
            x = d & -d
            v = nth_parent[x.bit_length() - 1][v]
            d -= x
        
        if u == v:
            return u
    
        for i in range(19, -1, -1):
            if nth_parent[i][u] != nth_parent[i][v]:
                u = nth_parent[i][u]
                v = nth_parent[i][v]
        
        return parent[u]
    
    def kth_parent(k, u):
        for i in range(20):
            if k >> i & 1:
                u = nth_parent[i][u]
        return u
    
    seg = LazySegTree(merge, 10 ** 15 * (n + 1), mapping, composition, 0, [1] * n)
    total_lazy = 0
    
    outs = []
    
    for _ in range(q):
        u, v, x, y, z = MII()
        u -= 1
        v -= 1
        x -= z
        y -= z
        total_lazy += z
        
        if u != v:
            l = lca(u, v)
            d = depth[u] + depth[v] - depth[l] * 2
            
            for _ in range(2):
                if depth[u] - depth[l] > (d - 1) // 2:
                    pos = kth_parent((d - 1) // 2, u)
                    seg.apply(ls[pos], rs[pos], x)
                else:
                    pos = kth_parent(d - 1 - (d - 1) // 2, v)
                    total_lazy += x
                    seg.apply(ls[pos], rs[pos], -x)
                
                u, v = v, u
                x, y = y, x
        
        val, cnt = divmod(seg.all_prod(), n + 1)
        val += total_lazy
        
        outs.append(f'{val} {cnt}')
    
    print('\n'.join(outs))