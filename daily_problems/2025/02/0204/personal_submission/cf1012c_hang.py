def main():
    n = int(input())
    a = list(map(int, input().split()))
    k = (n + 1) // 2
    ans = [-1] * k
    cost = [0] * n
    inf = 10**9
    for i in range(n):
        if i:
            cost[i] += max(0, a[i-1] - a[i] + 1)
        if i + 1 < n:
            cost[i] += max(0, a[i+1] - a[i] + 1)
    # dp[i][j] 表示前i个数，选择j个作为山顶并且第i个数是山顶的最小代价
    dp = cost[:]
    ans[0] = min(dp)
    pre = [0] * n
    for i in range(1, k):
        pre[0] = dp[0]
        for j in range(1,n): 
            pre[j] = min(pre[j-1], dp[j])
        for j in range(n-1, 1, -1):
            dp[j] = pre[j-2] + cost[j] # 如果第j-2个不是山顶时的最小代价（这里其实包括第j-2个是山顶的情况，不过无所谓，下一步就会减去重复的）
            dp[j] = min(dp[j], dp[j-2] + cost[j] - max(a[j-1] - max(a[j],a[j-2]) + 1, 0)) # 如果第j-2个是山顶时的最小代价
        dp[0] = dp[1] = inf
        ans[i] = min(dp)
    print(*ans)

main()