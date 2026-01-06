# Submission link: https://codeforces.com/gym/104287/submission/356585665
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v, w = MII()
            u -= 1
            v -= 1
            path[u].append(w * n + v)
            path[v].append(w * n + u)
        
        parent = [-1] * n
        que = [0]
        
        for u in que:
            for msk in path[u]:
                w, v = divmod(msk, n)
                if parent[u] != v:
                    parent[v] = u
                    que.append(v)
        
        dp0 = [0] * n
        dp1 = [0] * n
        
        for u in reversed(que):
            v1, v2 = 0, 0
            
            for msk in path[u]:
                w, v = divmod(msk, n)
                if parent[v] == u:
                    nw = w + dp0[v]
                    if nw > v1: v1, v2 = nw, v1
                    elif nw > v2: v2 = nw
                    dp1[u] = fmax(dp1[u], dp1[v])
            
            dp0[u] = v1
            dp1[u] = fmax(dp1[u], v1 + v2)
        
        up_dp0 = [0] * n
        up_dp1 = [0] * n
        
        for u in que:
            v1, v2, v3 = up_dp0[u], 0, 0
            w1, w2 = 0, 0
            
            for msk in path[u]:
                w, v = divmod(msk, n)
                
                if parent[v] == u:
                    nw = w + dp0[v]
                    if nw > v1: v1, v2, v3 = nw, v1, v2
                    elif nw > v2: v2, v3 = nw, v2
                    elif nw > v3: v3 = nw
                    
                    if dp1[v] > w1: w1, w2 = dp1[v], w1
                    elif dp1[v] > w2: w2 = dp1[v]
            
            for msk in path[u]:
                w, v = divmod(msk, n)
                
                if parent[v] == u:
                    nw = w + dp0[v]
                    if nw == v1:
                        up_dp0[v] = v2 + w
                        up_dp1[v] = v2 + v3
                    elif nw == v2:
                        up_dp0[v] = v1 + w
                        up_dp1[v] = v1 + v3
                    else:
                        up_dp0[v] = v1 + w
                        up_dp1[v] = v1 + v2
    
                    if dp1[v] == w1: up_dp1[v] = fmax(up_dp1[v], w2)
                    else: up_dp1[v] = fmax(up_dp1[v], w1)
        
        outs.append(max(fmin(dp1[i], up_dp1[i]) for i in range(n)))
    
    print('\n'.join(map(str, outs)))