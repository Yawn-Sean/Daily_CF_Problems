# Submission link: https://codeforces.com/gym/106241/submission/351954321
def main(): 
    n, m = MII()
    vis = [0] * n
    path = [[] for _ in range(n)]
    
    for i in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
        
        vis[u] = 1
        vis[v] = 1
    
    pt = 0
    to_check = []
    
    for i in range(n):
        if vis[i]:
            pt += 1
            vis[i] = pt
            to_check.append(i)
    
    dp = [0] * (pt + 1)
    dp[vis[0]] = 1
    
    mod = 998244353
    
    res = []
    for i in range(n):
        total = sum(dp) % mod
        if i: res.append(total)
        
        ndp = [0] * (pt + 1)
        for i in range(1, pt + 1):
            ndp[i] = total
        ndp[0] = (n - pt) * total % mod
        
        for u in to_check:
            for v in path[u]:
                ndp[vis[v]] -= dp[vis[u]]
                ndp[vis[v]] %= mod
        
        for i in range(pt + 1):
            ndp[i] -= dp[i]
            ndp[i] %= mod
        
        dp = ndp
    
    print(' '.join(map(str, res)))