def II():
    return int(input())

def LII():
    return list(map(int, input().split()))

n=II()
a=LII()
sm=sum(a)
mod=10**9+7
dp=[0]*(n+1)
dp[0]=1
P=[0]*(n+1)
for i in range(n):
    P[i+1]=P[i]+a[i]

window_sum=1
ptr=0

for i in range(1,n+1):
    while ptr<i and 2*(P[i]-P[ptr])>=sm:
        window_sum=(window_sum-dp[ptr])%mod
        ptr+=1
    dp[i]=window_sum
    window_sum=(window_sum+dp[i])%mod
print(dp[n])