# Submission link: https://codeforces.com/gym/105789/submission/354049655
def main(): 
    n, m = MII()
    nums = LII()
    
    us = []
    vs = []
    
    for _ in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
    
    st_range = sorted(range(m), key=lambda x: fmax(nums[us[x]], nums[vs[x]]))
    
    path = [[] for _ in range(2 * n - 1)]
    pt = n
    
    uf = UnionFind(n)
    notes = list(range(n))
    
    for i in st_range:
        u = us[i]
        v = vs[i]
        
        if uf.find(u) != uf.find(v):
            path[pt].append(notes[uf.find(u)])
            path[pt].append(notes[uf.find(v)])
            uf.merge(u, v)
            notes[uf.find(u)] = pt
            pt += 1
    
    val = [0] * (2 * n - 1)
    sz = [0] * (2 * n - 1)
    for i in range(n):
        sz[i] = 1
        val[i] = nums[i]
    
    for u in range(n, 2 * n - 1):
        for v in path[u]:
            sz[u] += sz[v]
            val[u] = fmax(val[u], val[v])
    
    ans = [0] * (2 * n - 1)
    
    que = [2 * n - 2]
    for u in que:
        for v in path[u]:
            ans[v] = ans[u] + (sz[u] - sz[v]) * val[u]
            que.append(v)
    
    for i in range(n):
        ans[i] += val[i]
    
    print(*ans[:n])