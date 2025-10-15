def solve():
    n,m=MII()
    G=[[False]*n for i in range(n)]
    for i in range(m):
        u,v=MII()
        u-=1;v-=1
        G[u][v]=G[v][u]=True
    state=[]
    ans=0
    def dfs(i):
        nonlocal ans
        if i==n:
            use=[[False]*6 for k in range(6)]
            res=0
            for u in range(n):
                for v in range(u,n):
                    if not G[u][v]:
                        continue
                    min_s=min(state[u],state[v])
                    max_s=max(state[u],state[v])
                    if not use[min_s][max_s]:
                        use[min_s][max_s]=True
                        res+=1
            ans=max(ans,res)
            return
        for j in range(6):
            state.append(j)
            dfs(i+1)
            state.pop()
        return
    dfs(0)
    print(ans)
    return
