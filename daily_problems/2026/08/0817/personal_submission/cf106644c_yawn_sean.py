# Submission link: https://codeforces.com/gym/106644/submission/387220121
def main():
    n, m = MII()
    
    path = [[] for _ in range(n)]
    
    uf1 = UnionFind(n)
    
    for _ in range(m):
        u, v = GMI()
        uf1.merge(u, v)
        path[u].append(v)
        path[v].append(u)
    
    uf2 = UnionFind(n)
    diff = [0] * n
    
    for i in range(n):
        path[i].sort()
        path[i].append(n)
        
        l = 0
        
        for j in path[i]:
            r = j
            
            if l < r:
                diff[l] += 1
                diff[r - 1] -= 1
                uf2.merge(i, l)
            
            l = r + 1
    
    for i in range(n - 1):
        diff[i + 1] += diff[i]
    
    for i in range(n):
        if diff[i]:
            uf2.merge(i, i + 1)
    
    ans = 0
    cnt = Counter()
    
    for i in range(n):
        u = uf1.find(i)
        v = uf2.find(i)
        
        ans += cnt[(u, v)]
        cnt[(u, v)] += 1
    
    print(ans)