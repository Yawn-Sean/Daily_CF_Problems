def II():
    return int(input())
def MII():
    return map(int, input().split())
    
t=II()
for _ in range(t):
    n=II()
    path=[[] for _ in range(n)]
    for _ in range(n-1):
        u,v=MII()
        u-=1
        v-=1
        path[u].append(v)
        path[v].append(u)
    rt=-1
    for i in range(n):
        if len(path[i])>3:
            print('No')
            break
        elif len(path[i])==3:
            rt=i
    else:
        if rt!=-1:
            parent=[-1]*(n)
            que=[rt]
            for u in que:
                for v in path[u]:
                    if parent[u]!=v:
                        parent[v]=u
                        que.append(v)
            vis=[0]*(n)
            for i in range(n):
                if len(path[i])==3:
                    cur=i
                    while cur>-1 and not vis[cur]:
                        vis[cur]=1
                        cur=parent[cur]
            flag = True
            for i in range(n):
                v = 0
                for j in path[i]:
                    v += vis[j]
                    if v >= 3:
                        print('No')
                        flag = False
                        break
                if not flag:
                    break
            if flag:
                print('Yes')
        else:
            print('Yes')