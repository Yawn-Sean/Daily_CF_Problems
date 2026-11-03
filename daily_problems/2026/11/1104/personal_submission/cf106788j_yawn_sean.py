# Submission link: https://codeforces.com/gym/106788/submission/397196951
def main(): 
    n, m, k = MII()
    inf = 10 ** 9
    
    path = [[] for _ in range(n)]
    ws = []
    
    for _ in range(m):
        u, v, w = MII()
        path[u].append(w * n + v)
        ws.append(w)
    
    ans = inf
    
    for w0 in ws:
        dis = [inf] * n
        dis[0] = 0
        
        pq = [0]
        while pq:
            d, u = divmod(heappop(pq), n)
            
            if dis[u] == d:
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    nd = d + fmax(w, w0)
                    
                    if nd < dis[v]:
                        dis[v] = nd
                        heappush(pq, dis[v] * n + v)
        
        ans = fmin(ans, dis[n - 1] - w0 * k)
    
    print(fmax(ans, 0))