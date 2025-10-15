# Submission link: https://codeforces.com/contest/1906/submission/312731816
def main():
    n = II()
    nums = LII()

    mod = 998244353

    # dp[i - 1][j - k] * 2 ^ (j - k - i + 1) -> dp[i][j]
    # 需要满足 j - k + 1, ..., j 是递增的
    prev = list(range(n))
    for i in range(1, n):
        if nums[i] > nums[i - 1]:
            prev[i] = prev[i - 1]

    dp = [0] * n
    acc = [0] * (n + 1)
    dp[0] = 1

    for i in range(1, n):
        pw = 1
        for j in range(i - 1, n):
            acc[j + 1] = (pw * dp[j] + acc[j]) % mod
            pw = pw * 2 % mod
        
        for j in range(i, n):
            dp[j] = (acc[j + 1] - acc[fmax(prev[j] - 1, 0)]) % mod
        
        for j in range(n + 1):
            acc[j] = 0

    print(dp[n - 1])