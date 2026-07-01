import sys
import heapq
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m=MII()
g=[[] for _ in range(n+1)]
for _ in range(m):
    u,v,w=LII()
    g[u].append((v,w))
INF=10**18
dist=[INF]*(n+1)
mxe=[INF]*(n+1)
dist[1]=0
mxe[1]=0
pq=[(0,0,1)]
while pq:
    d,mx,u=heapq.heappop(pq)
    if d>dist[u] or (d==dist[u] and mx>mxe[u]):
        continue
    for v,w in g[u]:
        nd=d+w
        nm=mx if mx>w else w
        if nd<dist[v] or (nd==dist[v] and nm<mxe[v]):
            dist[v]=nd
            mxe[v]=nm
            heapq.heappush(pq,(nd,nm,v))
print(dist[n],mxe[n])