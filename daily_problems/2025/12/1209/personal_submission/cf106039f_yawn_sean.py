# Submission link: https://codeforces.com/gym/106039/submission/352484100
def main(): 
    n, m, k = MII()
    path = [[] for _ in range(n + k)]
    
    for _ in range(m):
        u, v, c = MII()
        u -= 1
        v -= 1
        path[u].append(c * (n + k) + v)
        path[v].append(c * (n + k) + u)
    
    for u in range(n):
        t = II()
        for _ in range(t):
            v, c = MII()
            v = v - 1 + n
            path[u].append(c * (n + k) + v)
            path[v].append(u)
    
    inf = 10 ** 16
    dis = [inf] * (n + k)
    dis[0] = 0
    
    pq = [0]
    while pq:
        d, u = divmod(heappop(pq), n + k)
        if u == n - 1:
            print(d)
            break
        
        if dis[u] == d:
            for msk in path[u]:
                nd, v = divmod(msk, n + k)
                if dis[v] > nd + d:
                    dis[v] = nd + d
                    heappush(pq, dis[v] * (n + k) + v)