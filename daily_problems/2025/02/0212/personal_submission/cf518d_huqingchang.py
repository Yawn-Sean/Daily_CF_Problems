def main():
    res = LI()
    n, p, t = int(res[0]), float(res[1]), int(res[2])
    dp = [[0] * (t + 1) for _ in range(n + 1)]
    for q in range(1, n + 1):
        for ti in range(1, t + 1):
            dp[q][ti] = p * (dp[q - 1][ti - 1] + 1) + (1 - p) * dp[q][ti - 1]
    return dp[-1][-1]


T = 1
for ii in range(T):
    print(main())
