# Submission link: https://codeforces.com/gym/100488/submission/340841340
def main():
    n, m, k = MII()
    
    path = [[0] * n for _ in range(n)]
    
    for _ in range(m):
        u, v = GMI()
        path[u][v] = path[v][u] = 1
    
    vis = [0] * n
    
    pt = 0
    for i in range(n):
        if vis[i] == 0:
            pt += 1
            vis[i] = pt
            que = [i]
            for u in que:
                for v in range(n):
                    if path[u][v] == 0 and vis[v] == 0:
                        vis[v] = pt
    
    if pt > k: print(-1)
    else:
        for u in range(n):
            for v in range(n):
                if (vis[u] == vis[v]) == path[u][v]:
                    exit(print(-1))
        print(' '.join(map(str, vis)))