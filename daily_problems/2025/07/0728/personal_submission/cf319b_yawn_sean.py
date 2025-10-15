# Submission link: https://codeforces.com/contest/319/submission/331088244
def main():
    n = II()
    nums = LII()
    
    dp = [0] * n
    stk = []
    
    for i in range(n - 1, -1, -1):
        res = 0
        while stk and nums[stk[-1]] < nums[i]:
            res = fmax(res + 1, dp[stk.pop()])
        
        stk.append(i)
        dp[i] = res
    
    print(max(dp))