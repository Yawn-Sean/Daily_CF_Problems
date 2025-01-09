# Submission link: https://codeforces.com/contest/629/submission/300218277
def main():
    n, m = MII()
    s = I()

    mod = 10 ** 9 + 7

    dp = [[0] * 2001 for _ in range(2001)]
    dp[0][0] = 1

    for i in range(2000):
        for j in range(i + 1):
            if j:
                dp[i + 1][j - 1] += dp[i][j]
                if dp[i + 1][j - 1] >= mod:
                    dp[i + 1][j - 1] -= mod
            dp[i + 1][j + 1] += dp[i][j]
            if dp[i + 1][j + 1] >= mod:
                dp[i + 1][j + 1] -= mod

    cur = 0
    cur_min = 0

    for c in s:
        if c == '(': cur += 1
        else: cur -= 1
        cur_min = fmin(cur, cur_min)

    ans = 0
    for i in range(n - m + 1):
        for j in range(2001):
            if j + cur_min >= 0 and 0 <= j + cur <= 2000:
                ans += dp[i][j] * dp[n - m - i][j + cur] % mod
                if ans >= mod: ans -= mod

    print(ans)