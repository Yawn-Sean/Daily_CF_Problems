'''
https://codeforces.com/problemset/submission/518/305770054
'''
def solve(n: int, p: float, t: int) -> float:
    dp = [0] * (n + 1)
    dp[0] = 1

    for _ in range(t):
        for i in range(n - 1, -1, -1):
            dp[i + 1] += dp[i] * p
            dp[i] *= 1 - p

    return sum(i * d for i, d in enumerate(dp))
