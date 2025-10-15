# Submission link: https://codeforces.com/contest/406/submission/332505641
def main():
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    rs = list(range(n))
    stk = [n - 1]
    
    depth = [0] * n
    
    for i in range(n - 2, -1, -1):
        while len(stk) > 1:
            x, y = xs[i], ys[i]
            x1, y1 = xs[stk[-1]], ys[stk[-1]]
            x2, y2 = xs[stk[-2]], ys[stk[-2]]
            
            if (y1 - y) * (x2 - x) < (y2 - y) * (x1 - x):
                stk.pop()
            else:
                break
        
        rs[i] = stk[-1]
        depth[i] = depth[stk[-1]] + 1
        stk.append(i)
    
    nth_parent = [[0] * n for _ in range(20)]
    nth_parent[0] = rs
    
    for i in range(19):
        for j in range(n):
            nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]]
    
    q = II()
    outs = []
    
    for _ in range(q):
        u, v = GMI()
        
        if depth[u] < depth[v]:
            u, v = v, u
        
        d = depth[u] - depth[v]
        
        while d:
            k = d & -d
            x = k.bit_length() - 1
            d -= k
            u = nth_parent[x][u]
        
        if u == v: outs.append(u + 1)
        else:
            for i in range(19, -1, -1):
                if nth_parent[i][u] != nth_parent[i][v]:
                    u = nth_parent[i][u]
                    v = nth_parent[i][v]
            
            outs.append(nth_parent[0][u] + 1)
    
    print(' '.join(map(str, outs)))