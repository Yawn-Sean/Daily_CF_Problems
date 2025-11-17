# Submission link: https://codeforces.com/gym/105698/submission/349393093
def main(): 
    n = II()
    nums = LII()
    nums.sort()
    
    mod = 998244353
    
    dp = [[0] * n for _ in range(n)]
    dp_acc = [[0] * n for _ in range(n)]
    
    for i in range(n):
        pos = 0
        for j in range(i + 1, n):
            while pos < i and nums[i] + nums[pos] <= nums[j]:
                pos += 1
            
            if pos: dp[i][j] = dp_acc[pos - 1][i]
            dp[i][j] += 1
            dp[i][j] %= mod
            
            if i: dp_acc[i][j] = dp_acc[i - 1][j]
            dp_acc[i][j] += dp[i][j]
            dp_acc[i][j] %= mod
    
    ans = 0
    for x in dp:
        for y in x:
            ans += y
    
    print((ans + n) % mod)