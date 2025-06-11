dir4 = [(1, 0), (0, 1), (-1, 0), (0, -1)]
fmax = lambda a, b: a if a > b else b

m, n = map(int, input().split())
mp = {ch: i for i, ch in enumerate('DIMA')}
grid = [[mp[ch] for ch in input()] for _ in range(m)]

g = [[] for _ in range(m*n)]
indeg = [0] * (m*n)
for r, row in enumerate(grid):
    for c, x in enumerate(row):
        u = r * n + c
        for dr, dc in dir4:
            r2, c2 = r+dr, c+dc
            if 0 <= r2 < m and 0 <= c2 < n and (grid[r2][c2] - x) % 4 == 1:
                v = r2 * n + c2
                g[u].append(v)
                indeg[v] += 1

length = [1] * (m*n)

# 先删除从不合法起点开始的路径
stk = []
for u in range(m*n):
    if indeg[u] == 0:
        r, c = divmod(u, n)
        if grid[r][c] != 0:
            stk.append(u)

while stk:
    u = stk.pop()
    for v in g[u]:
        indeg[v] -= 1
        if indeg[v] == 0:
            stk.append(v)

for u in range(m*n):
    if indeg[u] == 0:
        r, c = divmod(u, n)
        if grid[r][c] == 0:
            stk.append(u)

while stk:
    u = stk.pop()
    for v in g[u]:
        length[v] = fmax(length[v], length[u] + 1)
        indeg[v] -= 1
        if indeg[v] == 0:
            stk.append(v)

if max(indeg) > 0:
    print('Poor Inna!')
else:
    ans = max(length) // 4
    print('Poor Dima!' if ans == 0 else str(ans))