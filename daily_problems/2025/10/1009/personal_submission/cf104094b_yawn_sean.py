# Submission link: https://codeforces.com/gym/104094/submission/342586261
def main():
    n, m = MII()
    s, t, l = MII()
    s -= 1
    t -= 1
    
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(w * n + v)
        path[v].append(w * n + u)
    
    inf = 10 ** 15
    mod = 10 ** 9 + 7
    
    dis = [inf] * n
    dis[t] = 0
    
    pq = [t]
    nodes = []
    
    while pq:
        d, u = divmod(heappop(pq), n)
        
        if dis[u] == d:
            nodes.append(u)
            
            for msk in path[u]:
                nd, v = divmod(msk, n)
                if dis[v] > nd + d:
                    dis[v] = nd + d
                    heappush(pq, dis[v] * n + v)
    
    from_s_dp = [0] * n
    from_s_dp[s] = 1
    
    nodes.reverse()
    
    for u in nodes:
        for msk in path[u]:
            d, v = divmod(msk, n)
            
            if dis[u] - dis[v] == d:
                from_s_dp[v] += from_s_dp[u]
                from_s_dp[v] %= mod
    
    if dis[s] == l:
        print(from_s_dp[t])
        exit()
    
    from_t_dp = [0] * n
    from_t_dp[t] = 1
    
    nodes.reverse()
    
    for u in nodes:
        for msk in path[u]:
            d, v = divmod(msk, n)
            
            if dis[v] - dis[u] == d:
                from_t_dp[v] += from_t_dp[u]
                from_t_dp[v] %= mod
    
    ans = 0
    
    for u in range(n):
        if from_s_dp[u]:
            for msk in path[u]:
                d, v = divmod(msk, n)
                
                if dis[s] - dis[u] + d + dis[v] == l and u != t:
                    ans += from_s_dp[u] * from_t_dp[v] % mod
                    ans %= mod
    
    print(ans)