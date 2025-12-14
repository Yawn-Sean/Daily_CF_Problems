# Submission link: https://codeforces.com/gym/106260/submission/353439423
def main(): 
    t = II()
    outs = []
    
    mod = 998244353
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        depth = [0] * n
        depth[0] = 1
        
        que = [0]
        for u in que:
            for v in path[u]:
                if depth[v] == 0:
                    depth[v] = depth[u] + 1
                    que.append(v)
        
        ans = 0
        for x in depth:
            ans += pow(x, -1, mod)
            ans %= mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))