# Submission link: https://codeforces.com/gym/105325/submission/376177630
def main():
    t = II()
    outs = []
    
    inf = 10 ** 9
    
    for _ in range(t):
        n, m = MII()
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v, w = MII()
            path[u].append(w * n + v)
        
        dp = [[inf] * n for _ in range(n)]
        
        for i in range(n): dp[i][0] = 0
        
        for i in range(n - 1, 0, -1):
            for j in range(n):
                for msk in path[j]:
                    w, nj = divmod(msk, n)
                    dp[i - 1][nj] = fmin(dp[i - 1][nj], dp[i][j] + i * w)
        
        outs.append(' '.join(map(str, (x if x < inf else -1 for x in dp[0][1:]))))
    
    print('\n'.join(outs))