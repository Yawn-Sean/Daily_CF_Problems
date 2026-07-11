# Submission link: https://codeforces.com/gym/102896/submission/381982817
def main():
    n = II()
    vs = []
    
    parent = [-1] * n
    
    for i in range(n):
        l, r, v = MII()
        l -= 1
        r -= 1
        
        if l >= 0: parent[l] = i
        if r >= 0: parent[r] = i
        
        vs.append(v)
    
    depth = [0] * n
    
    for i in range(1, n):
        depth[i] = depth[parent[i]] + 1
    
    st_range = sorted(range(n), key=lambda x: vs[x])
    sorted_vs = sorted(vs)
    
    nth_parent = [[-1] * n for _ in range(20)]
    
    nth_parent[0] = parent
    
    for i in range(19):
        for j in range(n):
            if nth_parent[i][j] != -1:
                nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]]
    
    def lca(u, v):
        if depth[u] > depth[v]: u, v = v, u
        d = depth[v] - depth[u]
        
        while d:
            x = d & -d
            bit = x.bit_length() - 1
            v = nth_parent[bit][v]
            d -= x
        
        if u == v: return u
        
        for i in range(19, -1, -1):
            if nth_parent[i][u] != nth_parent[i][v]:
                u = nth_parent[i][u]
                v = nth_parent[i][v]
        
        return parent[u]
    
    q = II()
    outs = []
    
    for _ in range(q):
        l, r = MII()
        
        if l > sorted_vs[-1]: outs.append(1)
        elif r < sorted_vs[0]: outs.append(1)
        else:
            pl = bisect.bisect_left(sorted_vs, l)
            pr = bisect.bisect_right(sorted_vs, r)
            
            if pl == 0: vl = 0
            else: vl = lca(st_range[pl], st_range[pl - 1])
            
            if pr == n: vr = 0
            else: vr = lca(st_range[pr], st_range[pr - 1])
            
            p = lca(vl, vr)
            if pl == 0 and pr == n: outs.append(1)
            else: outs.append(2 * (depth[vl] + depth[vr] - depth[p]) + 3)
    
    print('\n'.join(map(str, outs)))