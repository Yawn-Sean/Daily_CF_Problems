# Submission link: https://codeforces.com/contest/33/submission/332166432
def main():
    n = II()
    nums = LII()
    
    dp1, dp2, dp3 = 0, 0, 0
    for x in nums:
        dp3 = fmax(dp2, dp3) - x
        dp2 = fmax(dp1, dp2) + x
        dp1 -= x
    
    print(max(dp1, dp2, dp3))