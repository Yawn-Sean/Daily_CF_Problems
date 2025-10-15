# Submission link: https://codeforces.com/contest/76/submission/332794826
def main():
    n, m = MII()
    g, s = MII()
    
    us = []
    vs = []
    gs = []
    ss = []
    
    for _ in range(m):
        u, v, x, y = MII()
        u -= 1
        v -= 1
        
        us.append(u)
        vs.append(v)
        gs.append(x)
        ss.append(y)
    
    inf = 10 ** 18 * 3
    ans = inf
    
    used = [0] * m
    
    st_range_g = sorted(range(m), key=lambda x: gs[x])
    uf = UnionFind(n)
    
    cur = []
    
    for i in st_range_g:
        cur.append(i)
        
        for j in range(len(cur) - 1, 0, -1):
            if ss[cur[j]] < ss[cur[j - 1]]:
                cur[j], cur[j - 1] = cur[j - 1], cur[j]
        
        ncur = []
        
        uf.init()
        
        cnt = n
        cs = 0
        
        for eid in cur:
            if uf.merge(us[eid], vs[eid]):
                cnt -= 1
                cs = ss[eid]
                ncur.append(eid)
        
        if cnt == 1:
            ans = fmin(ans, gs[i] * g + cs * s)
        
        cur = ncur
    
    print(ans if ans < inf else -1)