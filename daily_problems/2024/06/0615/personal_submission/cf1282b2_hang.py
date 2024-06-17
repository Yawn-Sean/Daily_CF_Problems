def main():
    n,p,k = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    dp = [0]*(n+1)
    ans = 0
    for i in range(1,n+1):
        if i < k:
            dp[i] = dp[i-1] + a[i-1]
        else:
            dp[i] = dp[i-k] + a[i-1]
        if dp[i] <= p:
            ans = i
    print(ans)

t = int(input())
for _ in range(t):
    main()