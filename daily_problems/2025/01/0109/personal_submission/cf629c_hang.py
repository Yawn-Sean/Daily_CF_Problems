# 题解:https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2025/01/0109/solution/cf629c.md
def main():
    n, m = map(int, input().split())
    s = input()
    mod = 10**9 + 7
    dp = [[0] * 2001 for _ in range(2001)]
    dp[0][0] = 1
    for i in range(2000):
        for j in range(i + 1):

            if j != 0:
                dp[i + 1][j - 1] += dp[i][j]
                dp[i + 1][j - 1] %= mod
            dp[i + 1][j + 1] += dp[i][j]
            dp[i + 1][j + 1] %= mod

    cur = 0
    cur_min = 0
    for c in s:
        if c == '(': 
            cur += 1
        else: 
            cur -= 1
        cur_min = min(cur, cur_min)
    ans = 0
    for i in range(n - m + 1):
        for j in range(2001):
            if j + cur_min >= 0 and 0 <= j + cur <= 2000:
                ans += dp[i][j] * dp[n - m - i][j + cur] % mod
                ans %= mod
    print(ans)

main()