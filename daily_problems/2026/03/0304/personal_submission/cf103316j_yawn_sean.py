# Submission link: https://codeforces.com/gym/103316/submission/365217742
def main(): 
    n = II()
    nums = LII()
    
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    st_range = sorted(range(n), key=lambda x: nums[x])
    
    ans = 0
    mod = 10 ** 9 + 7
    
    vis = [0] * n
    uf = UnionFind(n)
    
    for u in st_range:
        for v in path[u]:
            if vis[v]:
                ans = (ans + nums[u] * uf.getSize(u) % mod * uf.getSize(v) % mod) % mod
                uf.merge(u, v)
        vis[u] = 1
    
    for i in range(n): vis[i] = 0
    uf.init()
    
    for u in reversed(st_range):
        for v in path[u]:
            if vis[v]:
                ans = (ans + mod - nums[u] * uf.getSize(u) % mod * uf.getSize(v) % mod) % mod
                uf.merge(u, v)
        vis[u] = 1
    
    print(ans * pow(n * (n - 1) // 2 % mod, -1, mod) % mod)