# Submission link: https://codeforces.com/gym/105500/submission/371461054
def main():
    n, k = MII()
    mod = 10 ** 9 + 7
    
    ans = 0
    dp = [0] * (n + 1)
    dp[0] = 1
    
    for i in range(k):
        ndp = [0] * (n + 1)
        
        for j in range(n + 1):
            if i and i + j <= n:
                dp[i + j] += dp[j]
                dp[i + j] %= mod
            if i + 1 <= n and j + 1 <= n:
                ndp[j + 1] += dp[j]
                ndp[j + 1] %= mod
        
        y = k - i
        for x in range(1, n // y + 1):
            ans += x * x * dp[n - y * x] % mod
            ans %= mod
        
        dp = ndp
    
    print(ans)