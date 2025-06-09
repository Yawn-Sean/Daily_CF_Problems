# Submission link: https://codeforces.com/contest/60/submission/321986798
def main():
    n, m = MII()

    us = [0] * m
    vs = [0] * m
    gcds = [0] * m
    lcms = [0] * m

    path = [[] for _ in range(n)]

    for i in range(m):
        us[i], vs[i], gcds[i], lcms[i] = MII()
        us[i] -= 1
        vs[i] -= 1
        path[us[i]].append(i)
        path[vs[i]].append(i)

    ans = [-1] * n

    for i in range(n):
        if ans[i] == -1:
            if len(path[i]) == 0:
                ans[i] = 1
                continue
            
            total_flg = False
            
            cur_l = 0
            for eid in path[i]:
                cur_l = math.gcd(cur_l, lcms[eid])
            
            for x in range(1, 1001):
                if cur_l % x == 0:
                    f = x
                    flg = True
                    
                    ans[i] = f
                    
                    stk = [i]
                    tmp = [i]
                    
                    
                    while stk:
                        u = stk.pop()
                        
                        for eid in path[u]:
                            v = us[eid] + vs[eid] - u
                            g = gcds[eid]
                            l = lcms[eid]
                            
                            if ans[u] == 0: break
                            
                            if ans[v] == -1:
                                ans[v] = g * l // ans[u]
                                tmp.append(v)
                                stk.append(v)
                            
                            if math.gcd(ans[u], ans[v]) != g or ans[u] * ans[v] != g * l:
                                flg = False
                                break
                    
                    if flg:
                        total_flg = True
                        break
                    
                    for u in tmp:
                        ans[u] = -1
                    
                    f = cur_l // x
                    flg = True
                    
                    ans[i] = f
                    
                    stk = [i]
                    tmp = [i]
                    
                    while stk:
                        u = stk.pop()
                        
                        for eid in path[u]:
                            v = us[eid] + vs[eid] - u
                            g = gcds[eid]
                            l = lcms[eid]
                            
                            if ans[u] == 0: break
                            
                            if ans[v] == -1:
                                ans[v] = g * l // ans[u]
                                tmp.append(v)
                                stk.append(v)

                            if math.gcd(ans[u], ans[v]) != g or ans[u] * ans[v] != g * l:
                                flg = False
                                break
                    
                    if flg:
                        total_flg = True
                        break
                    
                    for u in tmp:
                        ans[u] = -1

            if not total_flg:
                exit(print('NO'))

    print('YES')
    print(*ans)