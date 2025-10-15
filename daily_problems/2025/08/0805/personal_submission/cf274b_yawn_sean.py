# Submission link: https://codeforces.com/contest/274/submission/332357267
def main():
    n = II()
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    nums = LII()
    
    parent = [-1] * n
    q = [0]
    
    for u in q:
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                q.append(v)
    
    f = [0] * n
    g = [0] * n
    
    for u in reversed(q):
        cur = 0
        for v in path[u]:
            if parent[v] == u:
                f[u] = fmax(f[u], f[v])
                g[u] = fmax(g[u], g[v])
        
        k = nums[u] + f[u] - g[u]
        if k > 0: g[u] += k
        else: f[u] += -k
    
    print(f[0] + g[0])