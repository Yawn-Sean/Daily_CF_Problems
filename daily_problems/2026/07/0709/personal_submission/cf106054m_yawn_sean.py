# Submission link: https://codeforces.com/gym/106054/submission/381676346
def main():
    n, m, k = MII()
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    dis = [-1] * n
    dis[0] = 0
    
    que = [0]
    
    for u in que:
        for v in path[u]:
            if dis[v] == -1:
                dis[v] = dis[u] + 1
                que.append(v)
    
    if dis[1] == -1:
        print(0)
        exit()
    
    mod = 998244353
    f = Factorial(10000, mod)
    
    dp = [[0] * n for _ in range(k)]
    
    dp[0][0] = 1
    
    for i in range(k):
        for u in que:
            if dp[i][u] == 0:
                continue
            
            for v in path[u]:
                ni = dis[u] + i + 1 - dis[v]
                if ni < k:
                    dp[ni][v] += dp[i][u]
                    dp[ni][v] %= mod
    
    ans = 0
    days = (dis[1] - 1) // k + 1
    
    for i in range(k):
        if dis[1] + i <= days * k:
            res = 0
            
            for cnt in range(days + 1):
                resid = dis[1] + i - cnt * k
                if cnt % 2 == 0:
                    res += f.combi(resid - 1, days - 1) * f.combi(days, cnt) % mod
                else:
                    res += mod - f.combi(resid - 1, days - 1) * f.combi(days, cnt) % mod
                res %= mod
            
            ans += res * dp[i][1] % mod
            ans %= mod
    
    print(ans)