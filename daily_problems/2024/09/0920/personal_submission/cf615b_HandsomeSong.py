import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n,m=MII()
deg=[0]*(n+1)
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=MII()
    if u>v:
        u,v=v,u
    adj[u].append(v)
    deg[u]+=1
    deg[v]+=1
dp=[1]*(n+1)
for u in range(1,n+1):
    for v in adj[u]:
        if dp[u]+1>dp[v]:
            dp[v]=dp[u]+1
ans=0
for v in range(1,n+1):
    bt=dp[v]*deg[v]
    if bt>ans:
        ans=bt
print(ans)
