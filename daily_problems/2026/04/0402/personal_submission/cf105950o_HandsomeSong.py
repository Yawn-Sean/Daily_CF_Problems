from heapq import heappop, heappush
def II():
    return int(input())
def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))
    
n,m=MII()
path=[[]for _ in range(n)]
for _  in range(m):
    u,v,w=MII()
    path[u-1].append(w*n+v-1)
    path[v-1].append(w*n+u-1)

inf = 2*10**9
dis=[inf]*n
dis[0]=0
h=[0]
while h:
    d,u=divmod(heappop(h), n)

    if dis[u]==d:
        for msk in path[u]:
            w,v=divmod(msk,n)
            if dis[v]>max(d,w):
                dis[v]=max(d,w)
                heappush(h,dis[v]*n+v)


D=II()
d=[dis[x-1] for x in LII()]
e=LII()
d.sort()
e.sort()

ans=0
for i in range(D-1,-1,-1):
    if d[i]<=e[-1]:
        ans+=1
        e.pop()
print(ans)
