# Submission link: https://codeforces.com/gym/103575/submission/358465738
def main(): 
    n, m = MII()
    us = []
    vs = []
    ws = []
    
    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)
    
    uf1 = UnionFind(n)
    uf2 = UnionFind(n)
    
    for i in range(m):
        if ws[i] % 2 == 0:
            uf1.merge(us[i], vs[i])
    
    used = [0] * m
    even = 1
    
    for i in range(m):
        if ws[i] % 2 and uf1.merge(us[i], vs[i]):
            uf2.merge(us[i], vs[i])
            used[i] = 1
            even ^= 1
    
    if not even:
        for i in range(m):
            if ws[i] % 2 and not used[i] and uf2.merge(us[i], vs[i]):
                used[i] = 1
                even ^= 1
                break
    
    if not even: print('NO')
    else:
        for i in range(m):
            if ws[i] % 2 == 0 and uf2.merge(us[i], vs[i]):
                used[i] = 1
        
        print('YES')
        print(' '.join(str(i + 1) for i in range(m) if used[i]))
