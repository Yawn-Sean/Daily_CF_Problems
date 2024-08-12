n,m = RII()
a = RLIST()
opt = list(range(n))
for i in range(1,n):
    if a[i] == a[i-1]:
        opt[i] = opt[i-1]
ans = []
for _ in range(m):
    l,r,x = RII()
    l -= 1
    r -= 1
    if a[r] != x: ans.append(r + 1)
    else: ans.append(opt[r]  if opt[r] - 1 >= l else -1)
print('\n'.join(map(str,ans)))
