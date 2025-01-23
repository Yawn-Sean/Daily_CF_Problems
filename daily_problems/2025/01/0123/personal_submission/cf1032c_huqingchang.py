def main():
    n = II()
    res = LII()

    dp = [[0] * 6 for _ in range(n)]
    for i in range(1, 6):
        dp[0][i] = 1
    for i in range(1, n):
        x = res[i]
        y = res[i - 1]
        if y < x:
            for j in range(1, 5):
                if dp[i - 1][j]:
                    for k in range(j + 1, 6):
                        dp[i][k] = 1
                    break
        elif y > x:
            for j in range(5, 1, -1):
                if dp[i - 1][j]:
                    for k in range(1, j):
                        dp[i][k] = 1
                    break
        else:
            s = sum(dp[i - 1])
            for j in range(1, 6):
                if s - dp[i - 1][j]:
                    dp[i][j] = 1
        if sum(dp[i]) == 0:
            print(-1)
            return
    ans = [0] * n
    for j in range(1, 6):
        if dp[n - 1][j]:
            ans[n - 1] = j
            break
    for i in range(n - 2, -1, -1):
        x = res[i]
        pre = res[i + 1]
        if x < pre:
            for j in range(1, 6):
                if dp[i][j] and j < ans[i + 1]:
                    ans[i] = j
                    break
        elif x > pre:
            for j in range(1, 6):
                if dp[i][j] and j > ans[i + 1]:
                    ans[i] = j
                    break
        else:
            for j in range(1, 6):
                if dp[i][j] and j != ans[i + 1]:
                    ans[i] = j
                    break
    print(*ans)


T = 1
for ii in range(T):
    # print(main())
    main()
