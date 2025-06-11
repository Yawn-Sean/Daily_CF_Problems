# Submission link: https://codeforces.com/contest/1387/submission/293741896
def main():
    n, m = MII()
    
    us = []
    vs = []
    ws = []
    path = [[] for _ in range(n)]
    
    for i in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(i)
        path[v].append(i)
        us.append(u)
        vs.append(v)
        ws.append(w)
    
    notes_k = [0] * n
    notes_b = [0] * n
    ans = [0] * n
    vis = [0] * n
    
    stk = []
    for i in range(n):
        if notes_k[i] == 0:
            notes_k[i] = 1
            stk.append(i)
            
            flg = False
            val = 0
            
            vals = []
            eids = []
            while stk:
                u = stk.pop()
                vals.append(notes_k[u] * notes_b[u])
                for eid in path[u]:
                    eids.append(eid)
                    v = us[eid] + vs[eid] - u
                    w = ws[eid]
                    if notes_k[v] == 0:
                        notes_k[v] = -notes_k[u]
                        notes_b[v] = w - notes_b[u]
                        stk.append(v)
                    elif notes_k[u] == notes_k[v]:
                        flg = True
                        val = (w - notes_b[u] - notes_b[v]) / (notes_k[u] + notes_k[v])
            
            if not flg:
                vals.sort()
                val = vals[len(vals) // 2]
    
            stk.append(i)
            ans[i] = val
            vis[i] = 1
            
            while stk:
                u = stk.pop()
                for eid in path[u]:
                    v = us[eid] + vs[eid] - u
                    w = ws[eid]
                    if vis[v] == 0:
                        vis[v] = 1
                        ans[v] = w - ans[u]
                        stk.append(v)
            
            for eid in eids:
                if abs(ans[us[eid]] + ans[vs[eid]] - ws[eid]) > 0.1:
                    print('NO')
                    exit()
    
    print('YES')
    print(' '.join(map(str, ans)))