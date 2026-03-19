n=int(input())
a=[]
for _ in range(n):
    a.append(list(map(int,input().split())))
N = n + 1
g = [[0] * N for _ in range(N)]
for i in range(n):
    g[0][i + 1] = g[i + 1][0] = a[i][i]
    for j in range(n):
        g[i + 1][j + 1] = a[i][j]

used=[False]*N
dist=[10**18]*N
dist[0]=0
res=0
for _ in range(N):
    v=-1
    for i in range(N):
        if not used[i]and(v==-1 or dist[i]<dist[v]):
            v=i
    used[v]=True
    res+=dist[v]
    for i in range(N):
        if not used[i] and g[v][i] < dist[i]:
            dist[i] = g[v][i]

print(res)