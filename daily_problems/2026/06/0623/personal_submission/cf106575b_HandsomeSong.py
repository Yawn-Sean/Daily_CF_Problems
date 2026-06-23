import sys,heapq
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m,k,c=MII()
bad=[0]*(n+1)
for v in LII():
    bad[v]=1
f=[0]+LII()
adj=[[]for _ in range(n+1)]
for _ in range(m):
    u,v=MII()
    adj[u].append(v)
    adj[v].append(u)
vin=[0]*(n+1)
vout=[0]*(n+1)
N=n+1
for v in range(1,n+1):
    if bad[v]:
        vin[v],vout[v]=N,N+1
        N+=2
gg=[[] for _ in range(N)]
for v in range(1,n+1):
    if bad[v]:
        gg[vin[v]].append((vout[v],0))
        for u in adj[v]:
            if not bad[u]:
                gg[u].append((vin[v],f[v]))
                gg[vout[v]].append((u,0))
    else:
        for u in adj[v]:
            if not bad[u]:
                if u>v:
                    gg[u].append((v,0))
                    gg[v].append((u,0))
d=[1<<60]*N
d[1]=0
pq=[(0,1)]
while pq:
    x,u=heapq.heappop(pq)
    if x>d[u]:
        continue
    if u==n:
        break
    for v,w in gg[u]:
        if x+w<d[v]:
            d[v]=x+w
            heapq.heappush(pq,(d[v],v))
print(-1 if d[n]>c else d[n])