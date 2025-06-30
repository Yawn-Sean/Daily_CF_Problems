'''
https://codeforces.com/problemset/submission/30/326660030
'''
# DP(LIS)

# 参数a说明：为了便于排序，数组a存的元素调整为(t, x, y, p)
def solve(n: int, a: list[tuple[int, int, int, float]]) -> float:
    a.sort()
    dp = [0.0] * n
    for i in range(n):
        t, x, y, p = a[i]
        dp[i] = p
        for j in range(i):
            t0, x0, y0, _ = a[j]
            if (x - x0) ** 2 + (y - y0) ** 2 <= (t - t0) ** 2:
                dp[i] = max(dp[i], dp[j] + p)
    return max(dp)
