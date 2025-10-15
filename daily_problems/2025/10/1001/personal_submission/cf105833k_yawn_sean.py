# Submission link: https://codeforces.com/gym/105833/submission/341144947
def main():
    n, m, k = MII()
    
    us = []
    vs = []
    ws = []
    
    path = [[] for _ in range(n)]
    dsu = UnionFind(n)
    
    for _ in range(m):
        u, v, w = GMI()
        w += 1
        us.append(u)
        vs.append(v)
        ws.append(w)
        
        path[u].append(w * n + v)
        path[v].append(w * n + u)
        
        dsu.merge(u, v)
    
    tmp = []
    for i in range(m):
        if dsu.find(us[i]) == dsu.find(0):
            tmp.append(ws[i])
    
    ans = sum(nsmallest(k, tmp))
    
    inf = 10 ** 15
    
    dis = [inf] * n
    dis[0] = 0
    
    pq = [0]
    
    while pq:
        d, u = divmod(heappop(pq), n)
        if dis[u] == d:
            for msk in path[u]:
                nd, v = divmod(msk, n)
                if dis[v] > dis[u] + nd:
                    dis[v] = dis[u] + nd
                    heappush(pq, dis[v] * n + v)
    
    print(fmin(ans, dis[-1]))