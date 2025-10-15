# Submission link: https://codeforces.com/contest/605/submission/315070267
def main():
    n = II()
    nums = LII()

    dp = [0] * (n + 1)
    for v in nums:
        dp[v] = dp[v - 1] + 1

    print(n - max(dp))