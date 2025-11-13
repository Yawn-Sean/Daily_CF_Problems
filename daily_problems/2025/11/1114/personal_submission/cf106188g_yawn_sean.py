# Submission link: https://codeforces.com/gym/106188/submission/348719566
def main(): 
    mod = 10 ** 9 + 7
    
    n, k = MII()
    nums = LII()
    
    nums.sort()
    
    M = 10 ** 4 + 2
    dp = [[0] * M for _ in range(k)]
    dp[0][0] = 1
    
    ans = 0
    
    for i in range(n):
        for j in range(nums[i] + 1, M):
            ans += dp[k - 1][j]
            if ans >= mod:
                ans -= mod
        
        for x in range(k - 2, -1, -1):
            for y in range(M):
                ny = fmin(y + nums[i], M - 1)
                dp[x + 1][ny] += dp[x][y]
                if dp[x + 1][ny] >= mod:
                    dp[x + 1][ny] -= mod
    
    print(ans)