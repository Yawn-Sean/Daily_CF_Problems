import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n=II()
a=LII()
edge=[0]
tree=[[]for _ in range(n)]
for i in range(1,n):
    p,c=MII()
    edge.append(c)
    tree[p-1].append(i)
dp=[0]*n
stk=[0]
ans=0
while stk:
    u=stk.pop()
    ans+=1
    for v in tree[u]:
        dp[v]=max(0,dp[u]+edge[v])
        if dp[v]<=a[v]:
            stk.append(v)
print(n-ans)