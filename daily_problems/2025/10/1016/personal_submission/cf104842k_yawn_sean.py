# Submission link: https://codeforces.com/gym/104842/submission/343856829
def main(): 
    n = II()
    
    us = []
    vs = []
    path = [[] for _ in range(n)]
    
    for i in range(n - 1):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        path[u].append(i)
        path[v].append(i)
    
    parent = [-1] * n
    que = [0]
    
    for u in que:
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            if parent[u] != v:
                parent[v] = u
                que.append(v)
    
    dp1 = [0] * n
    
    for i in reversed(que):
        if i: dp1[parent[i]] = fmax(dp1[parent[i]], dp1[i] + 1)
    
    dp2 = [0] * n
    
    for u in que:
        v1, v2 = dp2[u], 0
        
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            if parent[v] == u:
                val = dp1[v] + 1
                if val > v1: v1, v2 = val, v1
                elif val > v2: v2 = val
        
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            if parent[v] == u:
                val = dp1[v] + 1
                if val == v1: dp2[v] = v2 + 1
                else: dp2[v] = v1 + 1
    
    ans = n
    x, y = -1, -1
    
    for i in range(1, n):
        v = fmax(dp1[i], dp2[i] - 1)
        if v < ans:
            ans = v
            x = i
            y = parent[i]
    
    print(ans)
    
    for i in range(n):
        parent[i] = -1
    
    parent[x] = y
    parent[y] = x
    
    que = [x, y]
    
    for u in que:
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            if parent[v] == -1:
                parent[v] = u
                que.append(v)
    
    ans = [0] * n
    
    for u in range(n):
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            if parent[u] == v:
                ans[u] = eid + 1
    
    print(*ans)