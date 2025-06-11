def main():
    n,m,k = map(int,input().split())
    s = input()
    t = input()
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for _ in range(k):
        for i in range(n):
            for j in range(m):
                if s[i] == t[j]:
                    dp[i + 1][j + 1] = dp[i][j] + 1
        for i in range(n):
            for j in range(m):
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1], dp[i + 1][j])
    print(dp[n][m])


main()