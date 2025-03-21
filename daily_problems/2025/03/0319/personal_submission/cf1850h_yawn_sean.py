# Submission link: https://codeforces.com/contest/1850/submission/311337226
def main():
    t = II()
    outs = []

    inf = 10 ** 15

    for _ in range(t):
        n, m = MII()
        path = [[] for _ in range(n + 1)]
        us = []
        vs = []
        ws = []
        
        for i in range(m):
            u, v, w = MII()
            
            us.append(u)
            vs.append(v)
            ws.append(w)
            
            path[u].append(i)
            path[v].append(i)
        
        cur = [inf] * (n + 1)
        
        flg = True
        for i in range(n + 1):
            if cur[i] == inf:
                cur[i] = 0
                
                stk = [i]
                while stk:
                    u = stk.pop()
                    for eid in path[u]:
                        if us[eid] == u:
                            v = vs[eid]
                            if cur[v] == inf:
                                cur[v] = cur[u] + ws[eid]
                                stk.append(v)
                            elif cur[v] != cur[u] + ws[eid]:
                                flg = False
                        else:
                            v = us[eid]
                            if cur[v] == inf:
                                cur[v] = cur[u] - ws[eid]
                                stk.append(v)
                            elif cur[v] != cur[u] - ws[eid]:
                                flg = False
        
        outs.append('YES' if flg else 'NO')

    print('\n'.join(outs))