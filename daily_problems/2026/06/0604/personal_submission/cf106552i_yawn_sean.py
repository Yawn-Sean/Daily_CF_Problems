# Submission link: https://codeforces.com/gym/106552/submission/377132153
def main():
    n, m, q = MII()
    path = [[] for _ in range(n + m)]
    
    for u in range(n):
        _, *idxs = GMI()
        
        for v in idxs:
            path[u].append(n + v)
            path[n + v].append(u)
    
    dis = [[-1] * (n + m) for _ in range(m)]
    
    for x in range(m):
        que = [n + x]
        dis[x][n + x] = 0
        
        for u in que:
            for v in path[u]:
                if dis[x][v] == -1:
                    dis[x][v] = dis[x][u] + 1
                    que.append(v)
    
    outs = []
    inf = 100000
    
    for _ in range(q):
        u, v = GMI()
        ans = inf
        
        for x in range(m):
            if dis[x][u] != -1 and dis[x][v] != -1:
                ans = fmin(ans, dis[x][u] + dis[x][v])
        
        outs.append(ans // 2 - 1 if ans < inf else -1)
    
    print('\n'.join(map(str, outs)))