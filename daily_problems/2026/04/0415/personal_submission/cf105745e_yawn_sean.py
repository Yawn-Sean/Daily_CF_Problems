# Submission link: https://codeforces.com/gym/105745/submission/371137215
def main():  
    x, y, z = MII()
    mod = 10 ** 9 + 7
    
    M = 301
    
    combs = [[0] * M for _ in range(M)]
    
    for i in range(M):
        combs[i][0] = 1
        combs[i][i] = 1
        
        for j in range(1, i):
            combs[i][j] = (combs[i - 1][j] + combs[i - 1][j - 1]) % mod
    
    def c(x, y):
        if x == y: return 1
        if y < 0 or y > x: return 0
        return combs[x][y]
    
    dp = [[0] * (M * M) for _ in range(3)]
    
    def f(i, j): return i * M + j
    
    dp[1][f(1, 0)] = 1
    dp[2][f(0, 1)] = 1
    
    ans = [0] * (x + y + z)
    
    for i in range(x + 1):
        ndp = [[0] * (M * M) for _ in range(3)]
        
        for j in range(y + 1):
            for k in range(z + 1):
                if i + j + k > 1:
                    if j:
                        dp[1][f(j, k)] = (dp[0][f(j - 1, k)] + dp[2][f(j - 1, k)]) % mod
                    if k:
                        dp[2][f(j, k)] = (dp[0][f(j, k - 1)] + dp[1][f(j, k - 1)]) % mod         
                for cur in range(3):
                    if i or j or k:
                        ans[i + j + k - 1] += dp[cur][f(j, k)] * c(x - 1, i - 1) % mod * c(y - 1, j - 1) % mod * c(z - 1, k - 1) % mod
                        ans[i + j + k - 1] %= mod
                
                ndp[0][f(j, k)] = (dp[1][f(j, k)] + dp[2][f(j, k)]) % mod
        
        if i == 0:
            ndp[0][f(0, 0)] = 1
    
        dp = ndp
    
    print(*ans, sep='\n')