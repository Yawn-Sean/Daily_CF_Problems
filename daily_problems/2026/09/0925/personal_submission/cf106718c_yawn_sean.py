# Submission link: https://codeforces.com/gym/106718/submission/391743273
def main():
    n, z = MII()
    
    ks = [0]
    ds = [1]
    xs = [0]
    
    for _ in range(n):
        k, d, x = MII()
        ks.append(k)
        ds.append(d)
        xs.append(x)
    
    dp = [[0] * (n + 1) for _ in range(z + 1)]
    
    for i in range(z):
        ma1 = 0
        ma2 = 0
        
        for j in range(n + 1):
            dp[i + 1][j] = fmax(dp[i + 1][j], dp[i][j] + ks[j] - xs[j])
            
            if dp[i][j] > ma1: ma1, ma2 = dp[i][j], ma1
            elif dp[i][j] > ma2: ma2 = dp[i][j]
        
        for j in range(n + 1):
            nd = fmin(z - i, ds[j])
            
            for x in range(1, nd + 1):
                dp[i + x][j] = fmax(dp[i + x][j], (ma2 if dp[i][j] == ma1 else ma1) + x * ks[j])
    
    print(max(dp[z]))