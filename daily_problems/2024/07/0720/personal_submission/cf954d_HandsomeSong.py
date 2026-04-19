from collections import deque
def MII():
    return map(int,input().split())
n,m,s,t=MII()
s-=1
t-=1
path=[[] for _ in range(n)]
is_edge=[[False]*n for _ in range(n)]
for _ in range(m):
    u,v=MII()
    u-=1
    v-=1
    path[u].append(v)
    path[v].append(u)
    is_edge[u][v]=True
    is_edge[v][u]=True
def bfs(start):
    dis=[-1]*n
    q=deque([start])
    dis[start]=0
    while q:
        u=q.popleft()
        for v in path[u]:
            if dis[v]==-1:
                dis[v]=dis[u]+1
                q.append(v)
    return dis
ds=bfs(s)
dt=bfs(t)
D=ds[t]
ans=0
for i in range(n):
    for j in range(i+1,n):
        if is_edge[i][j]:
            continue
        if ds[i]+1+dt[j] >=D and ds[j]+1+dt[i] >=D:
            ans +=1
print(ans)
