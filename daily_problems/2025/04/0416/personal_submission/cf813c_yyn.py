def yyn():
    n,a = MII()
    g = [[] for i in range(n)]
    for _ in range(n - 1):
        u,v = GMI()
        g[u].append(v)
        g[v].append(u)

    def cal(e,st):
        vis = [False] * n
        q = deque()
        q.append([0,st])
        dis = [0] * n
        while q:
            c,u = q.popleft()
            vis[u] = True
            dis[u] = c
            for v in g[u]:
                if not vis[v]:
                    q.append([c + 1,v])
        return dis

    d1 = cal(g,0)
    d2 = cal(g,a - 1)
    ans = -1
    for i in range(n):
        if d1[i] > d2[i]:
            ans = max(ans,d1[i] * 2)
    print(ans)
