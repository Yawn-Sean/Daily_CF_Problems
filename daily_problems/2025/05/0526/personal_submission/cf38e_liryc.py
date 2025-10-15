'''
https://codeforces.com/problemset/submission/38/321338061
'''
# DP, prefix sum (OTK)
def solve(n: int, xca: list[list[int]]) -> int:
    xca.sort()
    pre = [0] * n
    for i in range(n):
        pre[i] = xca[i][0]
        if i:
            pre[i] += pre[i - 1]

    dp0, dp1 = [-1] * n, [-1] * n
    dp0[0], dp1[0] = xca[0][1], xca[0][1]
    for i in range(1, n):
        dp1[i] = xca[i][1] + min(dp0[i - 1], dp1[i - 1])
        dp0[i] = dp1[0] + pre[i] - pre[0] - xca[0][0] * i
        for j in range(i):
            dp0[i] = min(dp0[i], dp1[j] + pre[i] - pre[j] - xca[j][0] * (i - j))
    return min(dp0[-1], dp1[-1])

