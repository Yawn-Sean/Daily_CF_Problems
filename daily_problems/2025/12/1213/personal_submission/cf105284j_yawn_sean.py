# Submission link: https://codeforces.com/gym/105284/submission/353151334
def main(): 
    n, m = MII()
    grid = [LII() for _ in range(n)]
    
    if n < m:
        n, m = m, n
        grid = [list(x) for x in zip(*grid)]
    
    mod = 998244353
    
    dp = [0] * (1 << m)
    dp[0] = 1
    
    rev2 = pow(2, -1, mod)
    rev6 = pow(6, -1, mod)
    
    for i in range(n):
        ndp = [0] * (1 << m)
        
        for j in range(m):
            v = grid[i][j]
            v0 = (v + 1) % mod
            v1 = v * (v + 1) % mod * rev2 % mod
            v2 = v * (v + 1) % mod * (2 * v + 1) % mod * rev6 % mod
            
            for msk in range((1 << m) - 1, -1, -1):
                ndp[msk] = (ndp[msk] * v0 + dp[msk] * v1) % mod
                dp[msk] = dp[msk] * v0 % mod
    
                if msk >> j & 1:
                    nmsk = msk ^ (1 << j)
                    
                    ndp[msk] = (ndp[msk] + dp[nmsk] * v2 + ndp[nmsk] * v1) % mod
                    dp[msk] = (dp[msk] + dp[nmsk] * v1) % mod
        
        dp = ndp
    
    print(dp[-1])