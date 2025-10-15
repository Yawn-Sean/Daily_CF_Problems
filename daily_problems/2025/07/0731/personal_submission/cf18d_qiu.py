def solve():
    import math

    n = int(input())
    ve = [(0, 0) for _ in range(n)]

    for i in range(n):
        s, x = input().split()
        x = int(x)
        if s == "win":
            ve[i] = (0, x)
        else:
            ve[i] = (1, x)

    dp = [0] * n
    for i in range(n):
        if i:
            dp[i] = max(dp[i], dp[i - 1])
        if ve[i][0] == 1:
            for j in range(i - 1, -1, -1):
                if ve[i][0] != ve[j][0] and ve[i][1] == ve[j][1]:
                    dp[i] = max(dp[i], dp[j] + pow(2, ve[j][1]))
    print(dp[n - 1])


if __name__ == "__main__":
    solve()
