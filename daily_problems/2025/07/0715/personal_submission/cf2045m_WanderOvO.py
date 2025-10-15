"""
枚举所有可能的位置，然后模拟即可
如何实现反射
设置移动向量 (dx, dy), 则移动向量有 (1, 0), (-1, 0), (0, 1), (0, -1)
对于 /:
- (1, 0) 变 (0, -1)
- (-1, 0) 变 (0, 1)
- (0, 1) 变 (-1, 0) 光路可逆
- (0, -1) 变 (1, 0)

对于 \:
- (1, 0) 变 (0, 1)
- (-1, 0) 变 (0, -1)
- (0, 1) 变 (1, 0) 光路可逆
- (0, -1) 变 (-1, 0)
"""

turn1, turn2 = {}, {}
# /
turn1[(1, 0)] = (0, -1)
turn1[(-1, 0)] = (0, 1)
turn1[(0, 1)] = (-1, 0)
turn1[(0, -1)] = (1, 0)
# \
turn2[(1, 0)] = (0, 1)
turn2[(-1, 0)] = (0, -1)
turn2[(0, 1)] = (1, 0)
turn2[(0, -1)] = (-1, 0)

n, m = map(int, input().split())
grid = []
for i in range(n):
    s = input()
    grid.append(s)

res = []
# N
for num in range(m):
    direction = (1, 0)
    cur_x, cur_y = 0, num
    vis = [[False for _ in range(m)] for _ in range(n)]
    cnt = 0
    while True:
        cnt += 1
        if cnt > 2 * n * m:
            break
        if cur_x >= 0 and cur_x < n and cur_y >= 0 and cur_y < m:
            vis[cur_x][cur_y] = True
            if grid[cur_x][cur_y] == '/':
                direction = turn1[direction]
            elif grid[cur_x][cur_y] == '\\':
                direction = turn2[direction]

            cur_x += direction[0]
            cur_y += direction[1]
        else:
            break
    ok = True
    for i in range(n):
        for j in range(m):
            if grid[i][j] != '.' and not vis[i][j]:
                ok = False
                break
    if ok:
        res.append(f'N{num + 1}')

# S
for num in range(m):
    direction = (-1, 0)
    cur_x, cur_y = n - 1, num
    vis = [[False for _ in range(m)] for _ in range(n)]
    cnt = 0
    while True:
        cnt += 1
        if cnt > 2 * n * m:
            break
        if cur_x >= 0 and cur_x < n and cur_y >= 0 and cur_y < m:
            vis[cur_x][cur_y] = True
            if grid[cur_x][cur_y] == '/':
                direction = turn1[direction]
            elif grid[cur_x][cur_y] == '\\':
                direction = turn2[direction]

            cur_x += direction[0]
            cur_y += direction[1]
        else:
            break
    ok = True
    for i in range(n):
        for j in range(m):
            if grid[i][j] != '.' and not vis[i][j]:
                ok = False
                break
    if ok:
        res.append(f'S{num + 1}')

# W
for num in range(n):
    direction = (0, 1)
    cur_x, cur_y = num, 0
    vis = [[False for _ in range(m)] for _ in range(n)]
    cnt = 0
    while True:
        cnt += 1
        if cnt > 2 * n * m:
            break
        if cur_x >= 0 and cur_x < n and cur_y >= 0 and cur_y < m:
            vis[cur_x][cur_y] = True
            if grid[cur_x][cur_y] == '/':
                direction = turn1[direction]
            elif grid[cur_x][cur_y] == '\\':
                direction = turn2[direction]

            cur_x += direction[0]
            cur_y += direction[1]
        else:
            break
    ok = True
    for i in range(n):
        for j in range(m):
            if grid[i][j] != '.' and not vis[i][j]:
                ok = False
                break
    if ok:
        res.append(f'W{num + 1}')

# E
for num in range(n):
    direction = (0, -1)
    cur_x, cur_y = num, m - 1
    vis = [[False for _ in range(m)] for _ in range(n)]
    cnt = 0
    while True:
        cnt += 1
        if cnt > 2 * n * m:
            break
        if cur_x >= 0 and cur_x < n and cur_y >= 0 and cur_y < m:
            vis[cur_x][cur_y] = True
            if grid[cur_x][cur_y] == '/':
                direction = turn1[direction]
            elif grid[cur_x][cur_y] == '\\':
                direction = turn2[direction]

            cur_x += direction[0]
            cur_y += direction[1]
        else:
            break
    ok = True
    for i in range(n):
        for j in range(m):
            if grid[i][j] != '.' and not vis[i][j]:
                ok = False
                break
    if ok:
        res.append(f'E{num + 1}')

print(len(res))
print(*res)
