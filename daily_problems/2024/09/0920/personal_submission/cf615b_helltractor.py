# 开始用的BFS，被菊花图克制了，MLE
def CF615B_dp():
    n, m = MII()
    d = defaultdict(list)
    deg = [0] * (n + 1)
    for _ in range(m):
        u, v = MII()
        if u < v: u, v = v, u
        d[u].append(v)
        deg[u] += 1
        deg[v] += 1
    
    dp = [1] * (n + 1)
    for u in range(1, n + 1):
        for v in d[u]:
            dp[u] = max(dp[u], dp[v] + 1)
    print(max(x * y for x, y in zip(deg, dp)))
