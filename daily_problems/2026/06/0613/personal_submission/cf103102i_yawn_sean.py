# Submission link: https://codeforces.com/gym/103102/submission/378268422
def main():
    n = II()
    mod = 10 ** 9 + 7
    
    if n < 3:
        print(n)
    else:
        dp = [1] * (n + 1)
        
        for i in range(3, n):
            dp[n] += dp[i]
            dp[n] %= mod
            
            for j in range(2 * i - 1, n, i):
                dp[j] += dp[i]
                dp[j] %= mod
            
            for j in range(2 * i, n, i):
                dp[j] += dp[i]
                dp[j] %= mod
            
            for j in range(i + 1, n, i):
                dp[j] += dp[i]
                dp[j] %= mod
        
        print(dp[n] * 2 * n % mod)