# Submission link: https://codeforces.com/gym/106507/submission/375336683
def main():  
    n, k = MII()
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    mod = 10 ** 9 + 7
    f = Factorial(n, mod)
    
    parent = [-1] * n
    que = [0]
    
    for u in que:
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                que.append(v)
    
    sz = [1] * n
    dp = [0] * n
    
    for u in reversed(que):
        if u:
            p = parent[u]
            sz[p] += sz[u]
            dp[p] += dp[u] + f.combi(sz[u], k)
            dp[p] %= mod
    
    rev_dp = [0] * n
    
    for u in que:
        for v in path[u]:
            if parent[v] == u:
                cur = (dp[u] - dp[v] - f.combi(sz[v], k)) % mod
                rev_dp[v] = (rev_dp[u] + cur + f.combi(n - sz[v], k)) % mod
    
    print(' '.join(str((dp[i] + rev_dp[i]) % mod) for i in range(n)))
