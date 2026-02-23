# Submission link: https://codeforces.com/gym/104523/submission/364016972
def main(): 
    t = II()
    outs = []
    
    inf = 10 ** 9
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        dp = [[inf] * n for _ in range(n)]
        
        for i in range(1, n):
            dp[i][i - 1] = 0
        
        for diff in range(1, n):
            for l in range(n - diff):
                r = l + diff
                for i in range(l, r):
                    dp[l][r] = fmin(dp[l][r], dp[l][i] + dp[i + 1][r])
                
                ma = fmax(nums[l], nums[r])
                mi = fmin(nums[l], nums[r])
                
                for i in range(l + 1, r):
                    if fmax(ma, nums[i]) - fmin(mi, nums[i]) <= k:
                        dp[l][r] = fmin(dp[l][r], dp[l + 1][i - 1] + dp[i + 1][r - 1] + 1)
                
                if ma - mi <= k:
                    dp[l][r] = fmin(dp[l][r], dp[l + 1][r - 1] + 1)
        
        dp1 = [inf] * (n + 1)
        dp2 = [inf] * (n + 1)
        
        dp1[0] = 0
        dp2[0] = 0
        
        for i in range(n):
            if dp1[i + 1] > dp1[i] + 1 or (dp1[i + 1] == dp1[i] + 1 and dp2[i + 1] > dp2[i]):
                dp1[i + 1] = dp1[i] + 1
                dp2[i + 1] = dp2[i]
            
            for j in range(i, n):
                if dp[i][j] < inf:
                    if dp1[j + 1] > dp1[i] or (dp1[j + 1] == dp1[i] and dp2[j + 1] > dp2[i] + dp[i][j]):
                        dp1[j + 1] = dp1[i]
                        dp2[j + 1] = dp2[i] + dp[i][j]
        
        outs.append(f'{dp1[n]} {dp2[n]}')
    
    print('\n'.join(outs))