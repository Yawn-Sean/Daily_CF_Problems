# Submission link: https://codeforces.com/gym/106457/submission/370074432
def main(): 
    n, q = MII()
    cnt = [[0] * n for _ in range(n)]
    
    for _ in range(q):
        l, r = GMI()
        cnt[l][r] += 1
    
    for l in range(n):
        for r in range(n - 1, 0, -1):
            cnt[l][r - 1] += cnt[l][r]
    
    for l in range(1, n):
        for r in range(n):
            cnt[l][r] += cnt[l - 1][r]
    
    dp = [[0] * n for _ in range(n)]
    
    for i in range(n):
        dp[i][i] = cnt[i][i]
    
    for step in range(1, n):
        for l in range(n - step):
            r = l + step
            dp[l][r] = fmax(dp[l + 1][r], dp[l][r - 1]) + cnt[l][r]
    
    print(dp[0][n - 1])