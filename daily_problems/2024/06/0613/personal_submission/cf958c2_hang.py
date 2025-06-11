def  main():
    n,k,p = map(int,input().split())
    a = list(map(lambda x: int(x) % p,input().split()))
    INF = 10**9
    dp  = [[-INF] * p for _ in range(k)]
    dp[0][0] = 0
    pre = 0
    for i in range(n - 1):
        pre = (pre + a[i]) % p
        for i in range(k - 1, 0, -1):
            for j in range(p):
                dp[i][pre] = max(dp[i][pre], dp[i - 1][j] + (pre - j) % p)
    pre = (pre + a[-1])% p
    ans = max(dp[-1][j] + (pre - j) % p for j in range(p))
    print(ans)

main()