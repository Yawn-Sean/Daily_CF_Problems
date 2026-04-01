# Submission link: https://codeforces.com/gym/105950/submission/369107478
def main(): 
    n, m = MII()
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(w * n + v)
        path[v].append(w * n + u)
    
    inf = 2 * 10 ** 9
    dis = [inf] * n
    dis[0] = 0
    
    pq = [0]
    
    while pq:
        d, u = divmod(heappop(pq), n)
        
        if dis[u] == d:
            for msk in path[u]:
                w, v = divmod(msk, n)
                if dis[v] > fmax(d, w):
                    dis[v] = fmax(d, w)
                    heappush(pq, dis[v] * n + v)
    
    d = II()
    v1 = [dis[x] for x in GMI()]
    v2 = LII()
    
    v1.sort()
    v2.sort()
    
    ans = 0
    for i in range(d - 1, -1, -1):
        if v1[i] <= v2[-1]:
            ans += 1
            v2.pop()
    
    print(ans)