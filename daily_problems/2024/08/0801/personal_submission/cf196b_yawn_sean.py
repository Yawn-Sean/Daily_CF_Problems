# Submission link: https://codeforces.com/contest/196/submission/273791205
def main():
    n, m = MII()
    grid = [I() for _ in range(n)]

    def f(x, y):
        return x * m + y

    vis = [None] * (n * m)
    sx, sy = 0, 0

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'S':
                sx = i
                sy = j

    stk = [(sx, sy)]
    vis[f(sx, sy)] = (sx, sy)

    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    while stk:
        x, y = stk.pop()
        for dx, dy in dirs:
            nx = x + dx
            ny = y + dy
            px = nx % n
            py = ny % m
            if grid[px][py] != '#':
                if vis[f(px, py)] is not None:
                    if vis[f(px, py)] != (nx, ny):
                        print('Yes')
                        exit()
                else:
                    vis[f(px, py)] = (nx, ny)
                    stk.append((nx, ny))

    print('No')