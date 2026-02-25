# Submission link: https://codeforces.com/gym/103940/submission/364290163
def main(): 
    n, m, c = MII()
    mod = 10 ** 9 + 7
    
    needed = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        needed[v].append((u, w))
    
    dis = [c + 1] * n
    dis[0] = 1
    
    for _ in range(c):
        for u in range(1, n):
            res = 0
            for v, w in needed[u]:
                res += dis[v] + w
            dis[u] = fmin(dis[u], res)
    
    dp = [0] * (c + 1)
    dp[0] = 1
    
    for x in dis:
        for i in range(x, c + 1):
            dp[i] += dp[i - x]
            dp[i] %= mod
    
    print(sum(dp[1:]) % mod)