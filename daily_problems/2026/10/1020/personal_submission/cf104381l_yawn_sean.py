# Submission link: https://codeforces.com/gym/104381/submission/395224416
def main():
    n, m, T = MII()
    T -= 1
    
    uf = UnionFind(n)
    edges = []
    
    for _ in range(m):
        u, v, x = MII()
        u -= 1
        v -= 1
        if x == 0: uf.merge(u, v)
        else: edges.append((u, v, x))
    
    dp = [[inf] * n for _ in range(n)]
    dp[0][uf.find(0)] = 0
    
    ans = inf
    
    for i in range(n - 2):
        for u, v, x in edges:
            u = uf.find(u)
            v = uf.find(v)
            dp[i + 1][v] = fmin(dp[i + 1][v], dp[i][u] + i * x)
            dp[i + 1][u] = fmin(dp[i + 1][u], dp[i][v] + i * x)
    
    for i in range(n):
        ans = fmin(ans, dp[i][uf.find(T)])
    
    print(ans if ans < inf else -1)