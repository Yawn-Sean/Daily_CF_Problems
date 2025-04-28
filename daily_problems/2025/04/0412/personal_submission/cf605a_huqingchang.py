def main():
    n = II()
    arr = LII()
    vis = [0] * (n + 1)
    dp = [1] * (n + 1)
    for x in arr:
        if vis[x - 1]:
            dp[x] = dp[x - 1] + 1
        vis[x] = 1
    return n - max(dp)


T = 1
for ii in range(T):
    print(main())
