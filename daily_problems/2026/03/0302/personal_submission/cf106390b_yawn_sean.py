# Submission link: https://codeforces.com/gym/106390/submission/364972002
def main(): 
    t = II()
    outs = []
    
    inf = 10 ** 18
    
    for _ in range(t):
        n = II()
        path = [[] for _ in range(n)]
        
        for _ in range(n - 1):
            u, v, w = MII()
            u -= 1
            v -= 1
            path[u].append(w * n + v)
            path[v].append(w * n + u)
        
        parent = [-1] * n
        dis0 = [0] * n
        dis1 = [0] * n
        min_dis = [inf] * n
        
        que = [0]
        for u in que:
            min_dis[dis0[u]] = fmin(min_dis[dis0[u]], dis1[u])
            for msk in path[u]:
                w, v = divmod(msk, n)
                if parent[u] != v:
                    parent[v] = u
                    dis0[v] = dis0[u] + 1
                    dis1[v] = dis1[u] + w
                    que.append(v)
        
        for u in que:
            dis1[u] = fmin(dis1[u], min_dis[dis0[u]])
            for msk in path[u]:
                w, v = divmod(msk, n)
                if parent[v] == u:
                    dis1[v] = dis1[u] + w
        
        outs.append(' '.join(map(str, dis1)))
    
    print('\n'.join(outs))