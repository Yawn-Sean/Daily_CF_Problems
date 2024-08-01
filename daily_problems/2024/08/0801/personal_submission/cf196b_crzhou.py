dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def f(x, y):
    return x * m + y

def bfs(sx, sy):
    stack = [(sx, sy)]
    vis[f(sx, sy)] = (sx + 1) * 2000 + sy + 1
    while stack:
        x, y = stack.pop()
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            px, py = nx % n, ny % m
            if maze[px][py] != '#':
                if vis[f(px, py)] != 0:
                    if vis[f(px, py)] != (nx + 1) * 2000 + ny + 1:
                        return True
                else:
                    vis[f(px, py)] = (nx + 1) * 2000 + ny + 1
                    stack.append((nx, ny))
    return False

n, m = MII()
maze = [I() for _ in range(n)]

sx = sy = 0
for i in range(n):
    for j in range(m):
        if maze[i][j] == 'S':
            sx, sy = i, j
            break

vis = [0] * (n * m)

if bfs(sx, sy):
    print('Yes')
else:
    print('No')
