# Submission link: https://codeforces.com/contest/2014/submission/324701911
def main():
    t = II()
    outs = []

    inf = 10 ** 13

    for _ in range(t):
        n, m, h = MII()
        pos = LGMI()
        
        horses = [0] * n
        for u in pos:
            horses[u] = 1
        
        path = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v, w = MII()
            u -= 1
            v -= 1
            path[u].append(w * n + v)
            path[v].append(w * n + u)
        
        f = lambda x, y: x * (2 * n) + y
        
        d1 = [inf] * (2 * n)
        d1[0] = 0
        pq = [f(d1[0], 0)]
        
        while pq:
            d, u = divmod(heappop(pq), 2 * n)
            if d1[u] == d:
                flg = False
                if u >= n:
                    u -= n
                    flg = True
                elif horses[u]:
                    flg = True
                
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    if flg:
                        nd = d + w // 2
                        nv = v + n
                    else:
                        nd = d + w
                        nv = v
                    if d1[nv] > nd:
                        d1[nv] = nd
                        heappush(pq, f(nd, nv))
        
        d2 = [inf] * (2 * n)
        d2[n - 1] = 0
        pq = [f(d2[n - 1], n - 1)]
        
        while pq:
            d, u = divmod(heappop(pq), 2 * n)
            if d2[u] == d:
                flg = False
                if u >= n:
                    u -= n
                    flg = True
                elif horses[u]:
                    flg = True
                
                for msk in path[u]:
                    w, v = divmod(msk, n)
                    if flg:
                        nd = d + w // 2
                        nv = v + n
                    else:
                        nd = d + w
                        nv = v
                    if d2[nv] > nd:
                        d2[nv] = nd
                        heappush(pq, f(nd, nv))
        
        ans = inf
        for i in range(n):
            ans = fmin(ans, fmax(fmin(d1[i], d1[i + n]), fmin(d2[i], d2[i + n])))
        
        outs.append(ans if ans < inf else -1)

    print('\n'.join(map(str, outs)))