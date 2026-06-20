import sys
input=sys.stdin.readline
def MII():
    return map(int, input().split())
mod=10**9+7
n, m=MII()
grid=[-1]*n 
for _ in range(m):
    a, b=MII()
    grid[a-1]=b-1
vis=[0]*n
c=0
for i in range(n):
    if vis[i] == 0:
        cur=i
        path=[]
        while cur != -1 and vis[cur] == 0:
            vis[cur]=1
            path.append(cur)
            cur=grid[cur]
        if cur != -1 and vis[cur] == 1:
            c+=1
        for node in path:
            vis[node]=2
if n==m:
    print(c%mod)
    exit()
inv=[0]*(n-m+1)
inv[1]=1
exp=1
for i in range(2,n-m+1):
    inv[i]=(mod-mod//i)*inv[mod%i]%mod
    exp=(exp+inv[i])%mod

print((c+exp)%mod)