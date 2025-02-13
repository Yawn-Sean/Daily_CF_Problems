'''
https://codeforces.com/problemset/submission/167/303179355
'''
def solve(n, l, k, pa, a):
    dp = [[0] * 201 for _ in range(n + 1)]
    dp[0][k] = 1

    dp1 = [[0] * 201 for _ in range(n + 1)]

    for cr in [True, False]:
        for t in range(n):
            if (a[t] >= 0) == cr:
                for i in range(n + 1):
                    for j in range(201):
                        if dp[i][j]:
                            dp1[i][j] += (1 - pa[t]) * dp[i][j]
                            if a[t] >= 0:
                                dp1[i + 1][min(j + a[t], 200)] += pa[t] * dp[i][j]
                            else:
                                if j: 
                                    dp1[i + 1][j - 1] += pa[t] * dp[i][j]
                for i in range(n + 1):
                    dp[i][:] = dp1[i][:]
                    dp1[i][:] = repeat(0, 201)

    return sum(sum(r) for r in dp[l:])
