# Submission link: https://codeforces.com/gym/104158/submission/364440384
def main(): 
    n, m = MII()
    
    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    us = []
    vs = []
    
    for _ in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
    
    parent = [-1] * n
    depth = [0] * n
    que = [0]
    
    for u in que:
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                depth[v] = depth[u] + 1
                que.append(v)
    
    nth_parent = [[-1] * n for _ in range(20)]
    nth_parent[0] = parent
    
    for i in range(19):
        for j in range(n):
            if nth_parent[i][j] >= 0:
                nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]]
    
    ls = []
    
    for i in range(m):
        u = us[i]
        v = vs[i]
        
        if depth[u] > depth[v]:
            u, v = v, u
        
        d = depth[v] - depth[u]
        
        while d:
            x = d & -d
            v = nth_parent[x.bit_length() - 1][v]
            d -= x
        
        if u == v: ls.append(u)
        else:
            for i in range(19, -1, -1):
                if nth_parent[i][u] != nth_parent[i][v]:
                    u = nth_parent[i][u]
                    v = nth_parent[i][v]
            ls.append(parent[u])
    
    ans = 0
    
    cnt = [0] * n
    
    for u in ls:
        cnt[u] += 1
        ans -= cnt[u]
    
    for u in que:
        if u:
            cnt[u] += cnt[parent[u]]
    
    for i in range(m):
        u = us[i]
        v = vs[i]
        l = ls[i]
        
        ans += cnt[u] + cnt[v] - cnt[l]
        if parent[l] >= 0: ans -= cnt[parent[l]]
    
    print(ans)