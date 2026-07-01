import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,B=MII()
a=LII()
b=LII()
items=sorted(zip(a,b),key=lambda x:-x[1])
inf=10**18
dp=[inf]*(n+1)
dp[0]=0
for x,y in items:
    ndp=dp[:]
    for i in range(n,0,-1):
        ndp[i]=min(ndp[i],dp[i-1]+x+(i-1)*y)
    dp=ndp
ans=0
cost=0
for i in range(n,-1,-1):
    if dp[i]<=B:
        ans=i
        cost=dp[i]
        break
print(ans,cost)
