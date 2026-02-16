# Submission link: https://codeforces.com/contest/2195/submission/363303387
def main(): 
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n + 1)]
        path[0].append(1)
        for i in range(1, n + 1):
            u, v = MII()
            if u and v:
                path[i].append(u)
                path[i].append(v)
    
        que = [0]
        parent = [-1] * (n + 1)
        for u in que:
            for v in path[u]:
                parent[v] = u
                que.append(v)
    
        sz = [0] * (n + 1)
        
        for i in reversed(que):
            if path[i] and i > 0:
                u, v = path[i]
                sz[i] = (sz[u] + 2 + sz[v] + 2) % mod
        
        for i in que:
            for j in path[i]:
                sz[j] += sz[i] + 1
                sz[j] %= mod
        
        outs.append(' '.join(map(str, sz[1:])))
    
    print('\n'.join(map(str, outs)))