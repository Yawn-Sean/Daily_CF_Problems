n,x = MII()
a = []
for _ in range(n):
    a.append(LII())

g = defaultdict(list)

for l,r,w in sorted(a, key=lambda p : p[1]):
    g[r-l+1].append([r,w])

for v in g.values():
    for i in range(1,len(v)):
        v[i][1] = min(v[i][1] , v[i-1][1])
        
res = inf
for l,r,w in a:    
    v = g[x-r+l-1]
    lo, hi = 0 , len(v)
    while lo < hi:
        mid = (lo + hi) // 2
        if v[mid][0] < l:
            lo = mid + 1
        else:
            hi = mid        
    if lo != 0:
        res = min(res , w + v[lo - 1][1])
print(-1 if res == inf else res)
