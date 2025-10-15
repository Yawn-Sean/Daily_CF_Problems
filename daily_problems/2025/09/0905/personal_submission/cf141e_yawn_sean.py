# Submission link: https://codeforces.com/contest/141/submission/336879813
def main():
    n, m = MII()
    us = []
    vs = []
    cs = []
    
    for _ in range(m):
        u, v, c = LI()
        u = int(u) - 1
        v = int(v) - 1
        c = 1 if c == 'S' else 0
        us.append(u)
        vs.append(v)
        cs.append(c)
    
    if n % 2 == 0: exit(print(-1))
    
    target = n // 2
    ans = []
    
    uf_base = UnionFind(n)
    real_uf = UnionFind(n)
    
    for i in range(m):
        if cs[i] == 0:
            uf_base.merge(us[i], vs[i])
    
    for i in range(m):
        if cs[i] and uf_base.merge(us[i], vs[i]):
            real_uf.merge(us[i], vs[i])
            ans.append(i)
    
    for i in range(m):
        if len(ans) < target and cs[i] and real_uf.merge(us[i], vs[i]):
            ans.append(i)
    
    if len(ans) != target: exit(print(-1))
    
    for i in range(m):
        if cs[i] == 0 and real_uf.merge(us[i], vs[i]):
            ans.append(i)
    
    if len(ans) == n - 1:
        print(len(ans))
        print(' '.join(str(x + 1) for x in ans))
    else:
        print(-1)