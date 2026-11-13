# Submission link: https://codeforces.com/gym/106353/submission/398405222
def main():
    n = II()
    path = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        u, v, w = MII()
        u -= 1
        v -= 1
        path[u].append(w * n + v)
        path[v].append(w * n + u)
    
    parent = [-1] * n
    que = [0]
    
    for u in que:
        for msk in path[u]:
            w, v = divmod(msk, n)
            
            if u == 0 or parent[u] % n != v:
                parent[v] = w * n + u
                que.append(v)
    
    sz = [0] * n
    
    m = II()
    
    for _ in range(m):
        u, v = GMI()
        sz[u] ^= 1
        sz[v] ^= 1
    
    ans = 0
    
    for u in reversed(que):
        if u:
            w, p = divmod(parent[u], n)
            sz[p] ^= sz[u]
            ans += sz[u] * w
    
    print(ans)