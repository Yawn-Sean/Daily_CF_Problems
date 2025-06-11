'''
https://codeforces.com/problemset/submission/294/319597847
'''
# 01knapsack
def solve(n: int, a: list[int]) -> int:
    dp = [-1] * (201)
    dp[0] = 0
    sumw = sum(w for _, w in a)
    for t, w in a:
        for capacity in range(200, t - 1, -1):
            if dp[capacity - t] >= 0:
                dp[capacity] = max(dp[capacity], dp[capacity - t] + w)
    for capacity in range(201):
        if dp[capacity] >= 0 and dp[capacity] + capacity >= sumw:
            return capacity
