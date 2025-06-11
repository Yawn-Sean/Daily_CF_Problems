def main():
    n,m = map(int,input().split())
    g = [[] for _ in range(n + 1)]
    for _ in range(m):
        a,b = map(int,input().split())
        g[a].append(b)
        g[b].append(a)
    ans = 0
    dp = [1] * (n + 1)
    for i in range(1,n + 1):
        ans = max(ans, dp[i] * len(g[i]))
        for j in g[i]:
            if j > i:
                dp[j] = max(dp[j], dp[i] + 1)
    print(ans)


main()