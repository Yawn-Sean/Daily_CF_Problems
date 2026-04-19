def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
for i in range(n):
    a[i]-=1
dis=[-1]*n
dis[0]=0
que=[0]
for u in que:
    if u and dis[u-1]==-1:
        dis[u-1]=dis[u]+1
        que.append(u-1)
    if u+1 <n and dis[u+1]==-1:
        dis[u+1]=dis[u]+1
        que.append(u+1)
    if dis[a[u]]==-1:
        dis[a[u]]=dis[u]+1
        que.append(a[u])  
print(' '.join(map(str, dis)))