# Submission link: https://codeforces.com/contest/1280/submission/290159042
def main():
    t = II()
    outs = []

    for _ in range(t):
        k = II()
        n = 2 * k
        
        us = []
        vs = []
        ws = []
        
        path = [[] for _ in range(n)]
        
        for i in range(n - 1):
            u, v, w = MII()
            u -= 1
            v -= 1
            
            us.append(u)
            vs.append(v)
            ws.append(w)
            path[u].append(i)
            path[v].append(i)
        
        parent = [-1] * n
        parent_weight = [0] * n
        order = []
        
        stk = [0]
        
        while stk:
            u = stk.pop()
            order.append(u)
            for i in path[u]:
                v = us[i] + vs[i] - u
                if parent[u] != v:
                    parent[v] = u
                    parent_weight[v] = ws[i]
                    stk.append(v)
        
        sz = [1] * n
        for u in reversed(order):
            if u > 0:
                sz[parent[u]] += sz[u]
        
        mi = ma = 0
        for i in range(n):
            mi += sz[i] % 2 * parent_weight[i]
            ma += fmin(n - sz[i], sz[i]) * parent_weight[i]
        
        outs.append(f'{mi} {ma}')

    print('\n'.join(outs))