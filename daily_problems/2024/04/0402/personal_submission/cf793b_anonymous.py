n = II()
a = LII()
g = [[] for _ in range(n)]
for i in range(1 , n):
    fa , w = MII()
    g[fa - 1].append((i , w))
dist , diff = [0] * n , [0] * n
path = []
stk = [0]
while stk:
    u = stk.pop()
    if u >= 0:                           
        fa = bisect.bisect_left(path , dist[u] - a[u] , key = lambda p : dist[p])
        if fa:
            diff[path[fa-1]] -= 1
        if path:
            diff[path[-1]] += 1    
        path.append(u)       
        stk.append(~u)
        for v , w in g[u]:            
            dist[v] = dist[u] + w
            stk.append(v)    
    else:
        u = ~u
        for v , w in g[u]:
            diff[u] += diff[v]
        path.pop()        
print(*diff)
