# Submission link: https://codeforces.com/gym/105948/submission/355836334
def main(): 
    n = II()
    nums = LII()
    
    mod = 998244353
    
    f = Factorial(n, mod)
    
    dp = [[0] * (n * n + 1) for _ in range(n + 1)]
    dp[0][0] = 1
    
    for i in range(n):
        for j in range(i, -1, -1):
            for k in range(n * n + 1):
                if dp[j][k]:
                    dp[j + 1][k + nums[i]] += dp[j][k]
                    dp[j + 1][k + nums[i]] %= mod
    
    ans = [0] * (n + 1)
    
    for v in nums:
        for j in range(n):
            for k in range(n * n + 1):
                if dp[j][k]:
                    dp[j + 1][k + v] -= dp[j][k]
                    dp[j + 1][k + v] %= mod
        
        for j in range(1, n):
            for k in range(n * n + 1):
                if j * v > k:
                    ans[j + 1] += dp[j][k]
                    ans[j + 1] %= mod
        
        for j in range(n - 1, -1, -1):
            for k in range(n * n + 1):
                if dp[j][k]:
                    dp[j + 1][k + v] += dp[j][k]
                    dp[j + 1][k + v] %= mod
    
    for i in range(2, n + 1):
        ans[i] = ans[i] * f.combi_inv(n, i) % mod * f.inv(i) % mod
    