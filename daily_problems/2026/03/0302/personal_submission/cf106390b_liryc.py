'''
2026.3.2 Y1 1600
tree graph
'''
def solve(n, tg):     
    INF = 10 ** 18
    tg = [[] for _ in range(n)]
    parent = [-1] * n
    dis0 = [0] * n
    dis1 = [0] * n
    min_dis = [INF] * n
    que = [0]
    for u in que:
        min_dis[dis0[u]] = min(min_dis[dis0[u]], dis1[u])
        for msk in tg[u]:
            w, v = divmod(msk, n)
            if parent[u] != v:
                parent[v] = u
                dis0[v] = dis0[u] + 1
                dis1[v] = dis1[u] + w
                que.append(v)
    for u in que:
        dis1[u] = min(dis1[u], min_dis[dis0[u]])
        for msk in tg[u]:
            w, v = divmod(msk, n)
            if parent[v] == u:
                dis1[v] = dis1[u] + w
    return dis1    
