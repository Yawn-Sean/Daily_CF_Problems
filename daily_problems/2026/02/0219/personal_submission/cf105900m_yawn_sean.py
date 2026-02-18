# Submission link: https://codeforces.com/gym/105900/submission/363523859
def main(): 
    n, m = MII()
    path = [[] for _ in range(n)]
    
    def f(d, u):
        return d * n + u
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(f(w, v))
    
    inf = 10 ** 12
    
    dis = [inf] * n
    dis[0] = 0
    
    pq = [f(0, 0)]
    
    order = []
    
    while pq:
        d, u = divmod(heappop(pq), n)
        if dis[u] == d:
            order.append(u)
            for msk in path[u]:
                w, v = divmod(msk, n)
                if dis[v] > dis[u] + w:
                    dis[v] = dis[u] + w
                    heappush(pq, f(dis[v], v))
    
    ans = [inf] * n
    ans[0] = 0
    
    for u in order:
        for msk in path[u]:
            w, v = divmod(msk, n)
            if dis[v] == dis[u] + w:
                ans[v] = fmin(ans[v], fmax(ans[u], w))
    
    print(dis[n - 1], ans[n - 1])
