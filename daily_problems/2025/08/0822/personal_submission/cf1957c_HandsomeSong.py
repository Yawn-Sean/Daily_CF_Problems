import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))
t=II()
mod=10**9+7
dp=[1]*300005
for i in range(2,300005):
    dp[i]=(dp[i-1]+2*(i-1)*dp[i-2])%mod
mod=10**9+7
for _ in range(t):
    n,k=MII()
    ls=[]
    for _ in range(k):
        ls+=LII()
    used=len(set(ls))
    print(dp[n-used])
