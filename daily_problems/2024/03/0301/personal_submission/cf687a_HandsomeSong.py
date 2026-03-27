def MII():
    return map(int, input().split())

n,m=MII()
path=[[]for _ in range(n)]
for _ in range(m):
    u,v=MII()
    path[u].append(v)
    path[v].append(u)

color=[-1]*n
stack=[]
for i in range(n):
    if color[i]==-1:
        color[i]=0
        stack.append(i)
        while stack:
            u=stack.pop()
            for v in path[u]:
                if color[v]==-1:
                    stack.append(v)
                    color[v]=color[u]^1
                elif color[v]==color[u]:
                    print(-1)
                    exit()
v=sum(color)
print(v)
print(*(x + 1 for x in range(n) if color[x]))
print(n - v)
print(*(x + 1 for x in range(n) if not color[x]))