# Submission link: https://codeforces.com/gym/106575/submission/379757824
def main():
    n, m, k, c = MII()
    blocked = [0] * n
    
    for x in GMI():
        blocked[x] = 1
    
    cost = LII()
    
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v = GMI()
        
        if blocked[u] and blocked[v]: continue
        
        w = 0
        
        if blocked[u]: w = cost[u]
        if blocked[v]: w = cost[v]
        
        path[u].append(w * n + v)
        path[v].append(w * n + u)
    
    dis = [2 * c + 5] * n
    
    dis[0] = 0
    pq = [0]
    
    while pq:
        d, u = divmod(heappop(pq), n)
        
        if dis[u] == d:
            for msk in path[u]:
                w, v = divmod(msk, n)
                if d + w < dis[v]:
                    dis[v] = d + w
                    heappush(pq, dis[v] * n + v)
    
    print(dis[n - 1] // 2 if dis[n - 1] <= 2 * c else -1)