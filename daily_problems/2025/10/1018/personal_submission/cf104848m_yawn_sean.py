# Submission link: https://codeforces.com/gym/104848/submission/344380308
def main(): 
    n, m, T = MII()
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, l, c = MII()
        u -= 1
        v -= 1
        w = math.sqrt(l * c)
        
        path[u].append((v, w))
        path[v].append((u, w))
    
    pq = [(0, 0)]
    
    dis = [10 ** 15] * n
    dis[0] = 0
    
    while pq:
        d, u = heappop(pq)
        
        if dis[u] == d:
            for v, w in path[u]:
                nd = d + w
                if nd < dis[v]:
                    dis[v] = nd
                    heappush(pq, (dis[v], v))
    
    print(dis[-1] * dis[-1] / T)