# Submission link: https://codeforces.com/contest/756/submission/309424699
def main():
    n = II()
    nums = [-2000] + [II() for _ in range(n)]

    dp = [0] * (n + 1)
    p1, p2 = 0, 0

    for i in range(1, n + 1):
        dp[i] = dp[i - 1] + 20
        while nums[i] - nums[p1] >= 90:
            p1 += 1
        dp[i] = fmin(dp[i], dp[p1 - 1] + 50)
        while nums[i] - nums[p2] >= 1440:
            p2 += 1
        dp[i] = fmin(dp[i], dp[p2 - 1] + 120)

    print('\n'.join(str(dp[i + 1] - dp[i]) for i in range(n)))