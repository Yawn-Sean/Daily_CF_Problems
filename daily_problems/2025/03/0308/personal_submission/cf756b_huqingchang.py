def main():
    n = II()
    res = []
    for _ in range(n):
        res.append(II())
    i2, i3 = 0, 0
    dp = [0] * n
    dp[0] = 20
    for i in range(1, n):
        while res[i] - res[i2] >= 90:
            i2 += 1
        while res[i] - res[i3] >= 1440:
            i3 += 1
        dp[i] = min(dp[i - 1] + 20, dp[i2 - 1] + 50 if i2 >= 1 else 50, dp[i3 - 1] + 120 if i3 >= 1 else 120)
    print(20)
    for i in range(1, n):
        print(dp[i] - dp[i - 1])


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
