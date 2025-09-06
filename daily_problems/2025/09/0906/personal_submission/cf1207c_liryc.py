'''
https://codeforces.com/problemset/submission/1207/337146225
'''
# DP
def solve(n: int, a: int, b: int, s: list[int]) -> int:
    pmin = lambda x, y: x if y < 0 or x >= 0 and x <= y else y
    if n == 2:
        return (a + b << 1) + b
    dp = [[-1, -1] for _ in range(n)]
    dp[0][0] = a + (b << 1)
    dp[1][:] = -1 if s[1] == 1 else (a + b << 1) + b, 3 * a + 5 * b
    for i in range(2, n):
        h = s[i]
        if h == 0:
            dp[i][0] = pmin(dp[i - 1][0], dp[i - 1][1] + a) + a + b
        dp[i][1] = pmin(-1 if dp[i - 1][0] < 0 else dp[i - 1][0] + (a + b << 1) + b, dp[i - 1][1] + a + (b << 1))
    return dp[-1][0]
