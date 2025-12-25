# Submission link: https://codeforces.com/gym/105418/submission/355030106
def main(): 
    n, m = MII()
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(w * n + v)
    
    inf = 10 ** 15
    
    dis = [[inf] * n for _ in range(3)]
    dis[0][0] = 0
    
    def g(d, u, cur):
        return (d * n + u) * 3 + cur
    
    pq = [g(0, 0, 0)]
    
    while pq:
        v = heappop(pq)
        v, cur = divmod(v, 3)
        d, u = divmod(v, n)
        
        if dis[cur][u] == d:
            if cur == 0:
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    if dis[0][v] > d + w:
                        dis[0][v] = d + w
                        heappush(pq, g(dis[0][v], v, 0))
                    
                    if dis[1][v] > d + w // 2:
                        dis[1][v] = d + w // 2
                        heappush(pq, g(dis[1][v], v, 1))
            
            elif cur == 1:
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    if dis[2][v] > d + w // 2:
                        dis[2][v] = d + w // 2
                        heappush(pq, g(dis[2][v], v, 2))
            
            else:
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    if dis[2][v] > d + w:
                        dis[2][v] = d + w
                        heappush(pq, g(dis[2][v], v, 2))
    
    print(fmin(dis[1][n - 1], dis[2][n - 1]))