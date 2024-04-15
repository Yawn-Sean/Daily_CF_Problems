# Submission link: https://codeforces.com/contest/933/submission/256711239
def main():
    n = II()
    nums = LII()
    dp1, dp12, dp121, dp1212 = 0, 0, 0, 0

    for num in nums:
        if num == 1:
            dp1 += 1
            dp121 += 1
        else:
            dp12 += 1
            dp1212 += 1
        dp12 = max(dp1, dp12)
        dp121 = max(dp12, dp121)
        dp1212 = max(dp121, dp1212)

    print(dp1212)