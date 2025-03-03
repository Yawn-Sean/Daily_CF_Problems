def main():
    outs = []
    t = II()

    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        for _ in range(n - 1):
            u, v = GMI()
            path[u].append(v)
            path[v].append(u)
        
        dis = [-1] * n
        dis[0] = 0
        
        stk = [0]
        while stk:
            u = stk.pop()
            for v in path[u]:
                if dis[v] == -1:
                    dis[v] = dis[u] + 1
                    stk.append(v)
        
        u = dis.index(max(dis))
        dis = [-1] * n
        parent = [-1] * n
        
        dis[u] = 0
        stk = [u]
        while stk:
            u = stk.pop()
            for v in path[u]:
                if dis[v] == -1:
                    dis[v] = dis[u] + 1
                    stk.append(v)
                    parent[v] = u
        
        u = dis.index(max(dis))
        vis = [0] * n
        vis[u] = 1
        while parent[u] >= 0:
            u = parent[u]
            vis[u] = 1
        
        flg = True
        for i in range(n):
            if not vis[i]:
                for j in path[i]:
                    if vis[j]: break
                else: flg = False
        outs.append('YES' if flg else 'NO')

    print('\n'.join(outs))
