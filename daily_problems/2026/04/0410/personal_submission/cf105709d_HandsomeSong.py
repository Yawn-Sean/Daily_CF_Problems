def MII():
    return map(int, input().split())
n,m=MII()
dp=[[0]*(m+1)for _ in range(2)]
for _ in range(n):
    w,v=MII()
    for i in range(m,w-1,-1):
        dp[1][i]=max(dp[1][i],dp[1][i-w]+v)
    for i in range(m+1):
        dp[1][i]=max(dp[1][i],dp[0][i]+v)
    for i in range(m,w-1,-1):
        dp[0][i]=max(dp[0][i],dp[0][i-w]+v)
print(dp[1][-1])