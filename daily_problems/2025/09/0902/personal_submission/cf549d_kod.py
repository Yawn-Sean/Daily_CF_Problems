n, m = il()
g = [[1 if x == "W" else - 1 for x in input()] for _ in range(n)]
ans = 0
for i in range(n):
    for j in range(m):
        v = g[i][j]
        if i + 1 < n:
            v -= g[i + 1][j]
        if j + 1 < m:
            v -= g[i][j + 1]
        if i + 1 < n and j + 1 < m:
            v += g[i + 1][j + 1]
        if v:
            ans += 1
print(ans)
