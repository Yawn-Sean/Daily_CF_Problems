# Submission link: https://codeforces.com/gym/106728/submission/392571375
def main():
    n, m = MII()
    
    path = [[] for _ in range(n)]
    
    us = []
    vs = []
    ts = []
    hs = []
    
    for eid in range(m):
        u, v, t, h = MII()
        
        u -= 1
        v -= 1
        
        us.append(u)
        vs.append(v)
        ts.append(t)
        hs.append(h)
        
        path[u].append(eid)
        path[v].append(eid)
    
    inf = 2 * 10 ** 9
    
    latest_time = [-1] * n
    latest_time[0] = inf
    
    def f(x, y):
        return x * n + y
    
    pq = [f(-inf, 0)]
    
    while pq:
        d, u = divmod(heappop(pq), n)
        d = -d
        
        if latest_time[u] == d:
            for eid in path[u]:
                v = us[eid] ^ vs[eid] ^ u
                nd = fmin(d, hs[eid]) - ts[eid]
                
                if nd > latest_time[v]:
                    latest_time[v] = nd
                    heappush(pq, f(-latest_time[v], v))
    
    print(''.join('1' if x >= 0 else '0' for x in latest_time))