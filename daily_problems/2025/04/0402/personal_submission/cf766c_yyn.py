def yyn():
    n = II()
    s = [ord(c) - ord('a') for c in I()]
    a = LII()

    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(n):
        m = inf
        for j in range(i, n):
            m = min(m, a[s[j]])
            if m < j - i + 1:
                break
            dp[j + 1] = (dp[j + 1] + dp[i]) % mod1

    print(dp[-1])

    dp = [-inf] * (n + 1)
    dp[0] = 0
    for i in range(n):
        m = inf
        for j in range(i, n):
            m = min(m, a[s[j]])
            if m < j - i + 1:
                break
            dp[j + 1] = max(dp[j + 1],j - i + 1, dp[i])

    print(dp[-1])

    dp = [inf] * (n + 1)
    dp[0] = 0
    for i in range(n):
        m = inf
        for j in range(i, n):
            m = min(m, a[s[j]])
            if m < j - i + 1:
                break
            dp[j + 1] = min(dp[j + 1],dp[i] + 1)
    print(dp[-1])
