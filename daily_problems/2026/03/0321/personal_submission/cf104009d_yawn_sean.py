# Submission link: https://codeforces.com/gym/104009/submission/367479930
def main(): 
    n, m = MII()
    dsu = UnionFind(n * 2)
    
    ans = 1
    cur = []
    
    for _ in range(m):
        u, v = GMI()
    
        if dsu.find(u) == dsu.find(v):
            for x in cur:
                dsu.back(x)
                dsu.back(x + n)
    
            ans += 1
            cur.clear()
    
        dsu.merge(u, v + n)
        dsu.merge(v, u + n)
    
        cur.append(u)
        cur.append(v)
    
    print(ans)