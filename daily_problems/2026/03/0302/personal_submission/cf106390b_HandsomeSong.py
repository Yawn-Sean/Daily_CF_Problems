def II():
    return int(input())
def MII():
    return map(int, input().split())
inf=10**18
t=II()
for _ in range(t):
    n=II()
    path=[[]for _ in range(n)]
    for _ in range(n-1):
        u,v,w=MII()
        u-=1
        v-=1
        path[u].append(w*n+v)
        path[v].append(w*n+u)
    parent=[-1]*n
    dis0=[0]*n
    dis1=[0]*n
    min_dis=[inf]*n
    que=[0]
    for u in que:
        min_dis[dis0[u]]=min(min_dis[dis0[u]],dis1[u])
        for msk in path[u]:
            w,v=divmod(msk,n)
            if parent[u]!=v:
                parent[v]=u
                dis0[v]=dis0[u]+1
                dis1[v]=dis1[u]+w
                que.append(v)
    for u in que:
        dis1[u]=min(dis1[u],min_dis[dis0[u]])
        for msk in path[u]:
            w,v=divmod(msk,n)
            if parent[v]==u:
                dis1[v]=dis1[u]+w
    print(' '.join(map(str, dis1)))