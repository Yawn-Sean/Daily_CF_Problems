n,m = RII()
ans = inf
li = []
for _ in range(m):
    x,y = RII()
    a,b = x-1,y-1
    ans = min(ans,b-a+1)
res = []
for i in range(n):
    res.append(i % ans)
print(ans)
print(' '.join(map(str,res)))
