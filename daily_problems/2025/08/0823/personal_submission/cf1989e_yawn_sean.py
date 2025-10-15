# Submission link: https://codeforces.com/contest/1989/submission/335031669
def main():
    n, k = MII()
    mod = 998244353
    
    dp = [[0] * (n + 1) for _ in range(k + 1)]
    dp_acc = [[0] * (n + 1) for _ in range(k + 1)]
    
    for i in range(1, n + 1):
        dp[1][i] = 1
        dp_acc[1][i] = i
        
        for j in range(2, k + 1):
            dp[j][i] = dp[j - 1][i - 1]
            if i >= 3:
                dp[j][i] += dp_acc[j - 1][i - 3]
                dp[j][i] %= mod
            dp_acc[j][i] = (dp_acc[j][i - 1] + dp[j][i]) % mod
        
        dp[k][i] += dp[k][i - 1]
        dp[k][i] %= mod
        
        if i >= 3:
            dp[k][i] += dp_acc[k][i - 3]
            dp[k][i] %= mod
        
        dp_acc[k][i] = (dp_acc[k][i - 1] + dp[k][i]) % mod
    
    print((dp[k][n] + dp[k - 1][n - 2] + dp[k][n - 2]) % mod)