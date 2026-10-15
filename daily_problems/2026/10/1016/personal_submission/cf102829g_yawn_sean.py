# Submission link: https://codeforces.com/gym/102829/submission/394637136
def main():
    n = II()
    nums = LII()
    
    ans = 0
    
    M = 10 ** 4
    mod = 10 ** 9 + 7
    
    dp = [0] * (M + 1)
    ndp = [0] * (M + 1)
    
    for i in range(n):
        x = nums[i]
        dp[M // 2] += 1
        
        for j in range(M + 1):
            if j + x <= M: ndp[j + x] += dp[j]
            if j - x >= 0: ndp[j - x] += dp[j]
        
        for j in range(M + 1):
            dp[j] = ndp[j] % mod
            ndp[j] = 0
        
        ans += dp[M // 2]
    
    print(ans % mod)