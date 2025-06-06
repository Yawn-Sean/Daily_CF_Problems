'''
https://codeforces.com/problemset/submission/756/309435324
'''
def solve(n: int, a: list[int]) -> list[int]:
    dp = [0] * n
    i2, i3, d2, d3 = 0, 0, 0, 0
    for i, t in enumerate(a):
        dp[i] = 20
        if i > 0:
            dp[i] += dp[i - 1]
        while a[i2] + 90 <= t:
            d2 = dp[i2]
            i2 += 1
        while a[i3] + 1440 <= t:
            d3 = dp[i3]
            i3 += 1
        dp[i] = min(dp[i], d2 + 50, d3 + 120)
    return [dp[0]] + [y - x for x, y in pairwise(dp)]
