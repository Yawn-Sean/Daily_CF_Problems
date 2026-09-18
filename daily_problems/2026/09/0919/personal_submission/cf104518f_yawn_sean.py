# Submission link: https://codeforces.com/gym/104518/submission/391102226
def main():
    n, m = MII()
    
    us = []
    vs = []
    ws = []
    
    for _ in range(m):
        u, v, w = MII()
        us.append(u - 1)
        vs.append(v - 1)
        ws.append(w)
    
    uf = UnionFind(n)
    
    ans = 0
    path = [[] for _ in range(n)]
    
    for i in sorted(range(m), key=lambda x: ws[x]):
        u, v = us[i], vs[i]
        if uf.merge(u, v):
            ans += ws[i]
            path[u].append(v)
            path[v].append(u)
    
    parent = [-1] * n
    
    stk = [0]
    order = []
    
    while stk:
        u = stk.pop()
        
        if u >= 0:
            order.append(u)
            stk.append(~u)
            
            for v in path[u]:
                if parent[u] != v:
                    parent[v] = u
                    stk.append(v)
    
    res = [0]
    stk = [0]
    
    for u in order:
        if u:
            while res[-1] != parent[u]:
                stk.pop()
                res.append(stk[-1])
            stk.append(u)
            res.append(stk[-1])
    
    while stk[-1] != 0:
        stk.pop()
        res.append(stk[-1])
    
    print(ans * 2)
    print(len(res))
    print(' '.join(str(x + 1) for x in res))