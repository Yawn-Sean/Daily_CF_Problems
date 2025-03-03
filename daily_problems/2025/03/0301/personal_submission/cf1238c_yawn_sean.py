# Submission link: https://codeforces.com/contest/1238/submission/308426494
def main():
    t = II()
    outs = []

    for _ in range(t):
        h, n = MII()
        nums = LII()

        nums.append(0)
        nums.reverse()
        
        dp = [0] * (n + 1)
        for i in range(2, n + 1):
            if nums[i - 1] - nums[i - 2] == 1:
                dp[i] = dp[i - 2]
            else:
                dp[i] = dp[i - 1] + 1
        
        outs.append(dp[n])

    print('\n'.join(map(str, outs)))