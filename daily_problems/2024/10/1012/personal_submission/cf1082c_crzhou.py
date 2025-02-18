n, m = MII()
g = [[] for _ in range(m)]
for _ in range(n):
    s, r = MII()
    s -= 1
    g[s].append(r)

mx = 0
preg = []
for i in range(m):
    if g[i]:
        g[i].sort(reverse=True)
        g[i] = list(accumulate(g[i]))
        preg.append(g[i].copy())
        mx = fmax(mx, len(g[i]))
        
preg.sort(key=len)

cur = i = 0
ans = 0
while cur < mx:
    while len(preg[i]) <= cur:
        i += 1
    tmp = 0
    for j in range(i, len(preg)):
        if preg[j][cur] > 0:
            tmp += preg[j][cur]
    ans = fmax(ans, tmp)
    cur += 1

print(ans)
