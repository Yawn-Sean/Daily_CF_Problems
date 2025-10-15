# Submission link: https://codeforces.com/contest/1915/submission/320299711
def main():
    t = II()
    outs = []

    inf = 10 ** 12

    for _ in range(t):
        n, m = MII()
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v, w = MII()
            u -= 1
            v -= 1
            
            path[u].append(w * n + v)
            path[v].append(w * n + u)
        
        bikes = LII()

        def f(dist, pos, bike):
            return (dist * n + pos) * n + bike
        
        dis = [inf] * (n * n)
        
        dis[0] = 0
        pq = [f(0, 0, 0)]
        
        while pq:
            d, msk = divmod(heappop(pq), n * n)
            if dis[msk] == d:
                u, b = divmod(msk, n)
                
                for e_msk in path[u]:
                    w, v = divmod(e_msk, n)
                    
                    nd = d + w * bikes[b]
                    nb = b if bikes[b] <= bikes[v] else v
                    
                    nmsk = v * n + nb
                    
                    if dis[nmsk] > nd:
                        dis[nmsk] = nd
                        heappush(pq, f(nd, v, nb))
        
        outs.append(min(dis[(n - 1) * n + j] for j in range(n)))

    print('\n'.join(map(str, outs)))