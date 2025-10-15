# Submission link: https://codeforces.com/contest/95/submission/335235930
def main():
    n, m = MII()
    s, t = GMI()
    
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        
        path[u].append(w * n + v)
        path[v].append(w * n + u)
    
    inf = 10 ** 13
    dis = [[inf] * n for _ in range(n)]
    
    def f(d, node):
        return d * n + node
    
    for i in range(n):
        dis[i][i] = 0
        pq = [f(0, i)]
        
        while pq:
            d, u = divmod(heappop(pq), n)
            
            if dis[i][u] == d:
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    
                    if dis[i][v] > dis[i][u] + w:
                        dis[i][v] = dis[i][u] + w
                        heappush(pq, f(dis[i][v], v))
        
    ts = []
    cs = []
    
    for _ in range(n):
        x, y = MII()
        ts.append(x)
        cs.append(y)
    
    ans = [inf] * n
    ans[s] = 0
    
    pq = [f(0, s)]
    
    while pq:
        d, u = divmod(heappop(pq), n)
        
        if ans[u] == d:
            for v in range(n):
                if dis[u][v] <= ts[u]:
                    nd = d + cs[u]
                    if nd < ans[v]:
                        ans[v] = nd
                        heappush(pq, f(nd, v))
    
    print(ans[t] if ans[t] < inf else -1)