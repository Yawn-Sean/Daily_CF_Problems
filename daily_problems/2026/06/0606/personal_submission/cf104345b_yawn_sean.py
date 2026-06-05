# Submission link: https://codeforces.com/gym/104345/submission/377395423
def main():
    n = II()
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    parent = [-1] * n
    que = [0]
    
    for u in que:
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                que.append(v)
    
    q = II()
    outs = []
    
    vis = [0] * n
    uf = UnionFind(n)
    
    for _ in range(q):
        _, *nodes = GMI()
        
        for x in nodes:
            vis[x] = 1
        
        for x in nodes:
            if x and vis[parent[x]]:
                uf.merge(x, parent[x])
        
        ans = 0
        
        for x in nodes:
            if uf.find(x) == x:
                sz = uf.getSize(x)
                ans += sz * (sz - 1) // 2
        
        outs.append(ans)
        
        for x in nodes:
            vis[x] = 0
            uf.reset(x)
    
    print('\n'.join(map(str, outs)))