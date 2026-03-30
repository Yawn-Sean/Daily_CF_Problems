def II():
    return int(input())
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def I():
    return list(input())
    
t=II()
mod=998244353
for _ in range(t):
    n=II()
    path=[[]for _ in range(n)]
    
    for _ in range(n-1):
        u,v=MII()
        path[u-1].append(v-1)
        path[v-1].append(u-1)
    depth=[0]*n
    depth[0]=1

    que=[0]
    for u in que:
        for v in path[u]:
            if depth[v]==0:
                depth[v]=depth[u]+1
                que.append(v)

    ans=0
    for x in depth:
        ans+=pow(x,-1,mod)
        ans%=mod    
    
    print(ans)