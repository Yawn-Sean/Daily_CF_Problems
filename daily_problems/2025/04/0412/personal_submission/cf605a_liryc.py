'''
https://codeforces.com/problemset/submission/605/315114352
'''
# 寻找最大连续的子序列
def solve(n: int, a: list[int]) -> int:
    dp = [-1] * n
    m = 1
    for x in a:
        y = x - 1
        if y and dp[y - 1] > 0:
            dp[y] = dp[y - 1] + 1
            m = max(m, dp[y])
        else:
            dp[y] = 1
    return n - m
