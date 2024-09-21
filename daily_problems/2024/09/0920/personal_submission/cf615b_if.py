def solve():
    n, m = map(int, input().split())
    adj = [[] for i in range(n + 1)]
    for i in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    dp = [0] * (n + 1)
    ans = -1
    for i in range(1, n + 1):
        dp[i] = 1
        for j in adj[i]:
            if j < i:
                dp[i] = max(dp[i], dp[j] + 1)
        ans = max(ans, dp[i] * len(adj[i]))
    print(ans)
solve()
