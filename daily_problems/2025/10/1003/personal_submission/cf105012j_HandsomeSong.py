import sys
import math
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def f(a,b):
    if a>=b:
        return a+math.isqrt(b)
    else:
        return b+math.isqrt(a)
n=II()
a=[0]+LII()
adj=[[] for _ in range(n+1)]
for _ in range(n-1):
    u,v=MII()
    adj[u].append(v)
    adj[v].append(u)
parent=[0]*(n+1)
order=[]
q=[1]
head=0
while head<len(q):
    u=q[head]
    head+=1
    order.append(u)
    for v in adj[u]:
        if v!=parent[u]:
            parent[v]=u
            q.append(v)
dp=[0]*(n+1)
m1=[0]*(n+1)
m2=[0]*(n+1)
best=[0]*(n+1)
for u in reversed(order):
    dp[u]=a[u]
    for v in adj[u]:
        if v!=parent[u]:
            val=f(dp[v],a[u])
            dp[u]=max(dp[u],val)
            if val>m1[u]:
                m2[u]=m1[u]
                m1[u]=val
                best[u]=v
            elif val>m2[u]:
                m2[u]=val
up=[0]*(n+1)
for u in order:
    for v in adj[u]:
        if v!=parent[u]:
            if v==best[u]:
                best_p=max(a[u],up[u],m2[u])
            else:
                best_p=max(a[u],up[u],m1[u])
            up[v]=f(best_p,a[v])
ans=0
for i in range(1,n+1):
    ans=max(ans,dp[i],up[i])
print(ans)