def II():
    return int(input())
def MII():
    return map(int, input().split())
mod = 10 ** 9 + 7
    
t=II()
for _ in range(t):
    n=II()
    path=[[]for _ in range(n+1)]
    path[0].append(1)
    for i in range(1,n+1):
        u,v=MII()
        if u and v:
            path[i].append(u)
            path[i].append(v)
        
    tree=[0]
    for u in tree:
        for v in path[u]:
            tree.append(v)
    mk=[0]*(n+1)
    for i in reversed(tree):
        if path[i] and i>0:
            u,v=path[i]
            mk[i]=(mk[u]+2+mk[v]+2)%mod
    for i in tree:
        for j in path[i]:
            mk[j]+=mk[i]+1
            mk[j]%=mod
    print(' '.join(map(str,mk[1:])))