# Submission link: https://codeforces.com/gym/104847/submission/361423552
def main(): 
    t = II()
    outs = []
    inf = 10 ** 9
    
    for _ in range(t):
        n, m = MII()
        us = []
        vs = []
        ws = []
        
        for _ in range(m):
            u, v, w = GMI()
            us.append(u)
            vs.append(v)
            ws.append(w)
        
        st_range = sorted(range(m), key=lambda x: ws[x])
        dis = [inf] * n
        dis[0] = 0
        
        pt = 0
        while pt < m:
            npt = pt
            while npt < m and ws[st_range[npt]] == ws[st_range[pt]]:
                npt += 1
            
            updates = []
            for i in range(pt, npt):
                u = us[st_range[i]]
                v = vs[st_range[i]]
                updates.append((u, dis[v] + 1))
                updates.append((v, dis[u]))
            
            for u, d in updates:
                dis[u] = fmin(dis[u], d)
            
            pt = npt
        
        outs.append(dis[-1] if dis[-1] < inf else -1)
    
    print('\n'.join(map(str, outs)))