# Submission link: https://codeforces.com/contest/360/submission/277586586
def main():
    n, k = MII()
    nums = LII()

    l, r = 0, 2 * 10 ** 9
    dp = [1] * n

    while l <= r:
        m = (l + r) // 2
        for i in range(n):
            for j in range(i):
                if abs(nums[i] - nums[j]) <= m * (i - j):
                    dp[i] = fmax(dp[i], dp[j] + 1)
        if max(dp) + k >= n: r = m - 1
        else: l = m + 1
        for i in range(n):
            dp[i] = 1

    print(l)