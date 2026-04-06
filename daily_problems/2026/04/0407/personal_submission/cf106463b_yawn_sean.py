# Submission link: https://codeforces.com/gym/106463/submission/369976167
def main(): 
    t = II()
    outs = []
    
    M = 10 ** 5
    mod = 10 ** 9 + 7
    f = Factorial(M, mod)
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        que = [0]
        parent = [-1] * n
        
        for u in que:
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    que.append(v)
        
        dp = [1] * n
        sz = [1] * n
        
        for u in reversed(que):
            c0 = 0
            c1 = 0
            
            for v in path[u]:
                if parent[v] == u:
                    if sz[v]:
                        sz[u] ^= 1
                        c1 += 1
                    else:
                        c0 += 1
                    dp[u] = dp[u] * dp[v] % mod
    
            dp[u] = dp[u] * f.combi(c1, c1 // 2) % mod
            if c1: dp[u] = dp[u] * pow(2, c0) % mod
        
        outs.append(dp[0])
    
    print('\n'.join(map(str, outs)))