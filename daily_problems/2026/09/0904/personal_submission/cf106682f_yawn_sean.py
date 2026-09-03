# Submission link: https://codeforces.com/gym/106682/submission/389241630
def main():
    n, m = MII()
    
    us = []
    vs = []
    
    path = [[] for _ in range(n)]
    
    for eid in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        path[u].append(eid)
        path[v].append(eid)
    
    dis = [n] * n
    que = [0] * (4 * n)
    ans = [n] * m
    
    for i in range(m):
        l = r = 2 * n
    
        dis[0] = 0
        que[l] = 0
        
        while l <= r:
            u = que[l]
            l += 1
            
            for eid in path[u]:
                v = us[eid] + vs[eid] - u
                if eid >= i: nd = dis[u] + 1
                else: nd = dis[u]
                
                if dis[v] > nd:
                    if eid >= i:
                        dis[v] = nd
                        r += 1
                        que[r] = v
                    else:
                        dis[v] = nd
                        l -= 1
                        que[l] = v
    
        for j in range(i, m):
            ans[j] = fmin(ans[j], dis[n - 1] / (j - i + 1))
    
        for u in range(n):
            dis[u] = n
    
    print('\n'.join(f'{x:.9f}' for x in ans))