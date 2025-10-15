n, m = il()
a = il()
g = []
for i in range(m):
    x, y= il()
    g += [(x-1, y-1)]
uf = Uf(n)
ans = [[0]*n for i in range(n)]
for i in range(30):
    uf = Uf(n)
    for j in range(m):
        u, v = g[j]
        if a[u] >> i & 1 and a[v] >> i & 1:
            uf.union(u, v)
    for x in range(n):
        for y in range(n):
            if uf.find(x) == uf.find(y):
                ans[x][y] = 1

print('\n'.join(''.join(map(str, x)) for x in ans))
