def solve():
    n,k = MII()
    a = LII()
    g = [[] for _ in range(n)]
    for _ in range(n-1):
        u,v = MII()
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
    xs = reduce(xor , a)
    if xs == 0:
        print("YES")
        return 
    elif k <= 2:
        print("NO")
        return  
    cnt = 0    
    @bootstrap
    def dfs(u = 0 ,fa = -1):
        nonlocal cnt        
        for v in g[u]:
            if v == fa: continue
            yield dfs(v , u)
            if a[v] == xs:
                cnt += 1
                a[v] = 0
            a[u] ^= a[v]        
        yield
    dfs(0 , -1)
    print("YES" if cnt >= 2 else "NO")
                
for _ in range(II()):
    solve()
