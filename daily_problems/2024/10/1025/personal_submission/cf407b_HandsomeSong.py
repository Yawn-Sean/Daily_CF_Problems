def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
mod=10**9+7
n=II()
p=[0]+LII()
dp=[0]*(n+2)
for i in range(1,n+1):
    dp[i]=(2+2*dp[i-1]-dp[p[i]-1])%mod
print(dp[n])