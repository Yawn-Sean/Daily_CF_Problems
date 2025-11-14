# Submission link: https://codeforces.com/gym/106189/submission/348886288
def main(): 
    n = II()
    nums = LII()
    
    dp = [[0] * n for _ in range(n)]
    
    for diff in range(1, n):
        for l in range(n - diff):
            r = l + diff
            
            dp[l][r] = dp[l + 1][r - 1]
            if nums[l] % nums[r] == 0 or nums[r] % nums[l] == 0:
                dp[l][r] += 2
            
            for sep in range(l, r):
                dp[l][r] = fmax(dp[l][r], dp[l][sep] + dp[sep + 1][r])
    
    used = [0] * n
    
    def check(l, r):
        if l >= r: return
        
        for sep in range(l, r):
            if dp[l][r] == dp[l][sep] + dp[sep + 1][r]:
                check(l, sep)
                check(sep + 1, r)
                return 
    
        if nums[l] % nums[r] == 0 or nums[r] % nums[l] == 0:
            used[l] = 1
            used[r] = 1
        check(l + 1, r - 1)
    
    check(0, n - 1)
    
    print(n - dp[0][n - 1])
    print(*(i + 1 for i in range(n) if not used[i]))