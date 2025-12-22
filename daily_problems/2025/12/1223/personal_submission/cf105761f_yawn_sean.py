# Submission link: https://codeforces.com/gym/105761/submission/354505674
def main(): 
    n, p = MII()
    
    p = fmin(p, 20)
    dp = [[0] * (n + 1) for _ in range(p + 1)]
    
    for i in range(n + 1):
        dp[0][i] = 1
    
    inf = 10 ** 9
    for i in range(1, p + 1):
        dp[i][0] = 1
        
        for j in range(1, n + 1):
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]
            dp[i][j] = fmin(dp[i][j], inf)
    
    for i in range(n + 1):
        if dp[p][i] >= n:
            print(i)
            break