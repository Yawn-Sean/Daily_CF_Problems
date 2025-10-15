# Submission link: https://codeforces.com/contest/285/submission/328790057
def main():
    n, m = MII()

    d = {
        '.': 0,
        '\\': 1,
        '/': 3
    }

    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    grid = [[d[c] for c in I()] for _ in range(n)]

    target = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j]:
                target += 1

    ans = []

    def check(x, y, dir):
        saved_x = x
        saved_y = y
        saved_dir = dir
        while 0 <= x < n and 0 <= y < m:
            if grid[x][y]:
                vis[x][y] = 1
                dir ^= grid[x][y]
            dx, dy = dirs[dir]
            x += dx
            y += dy
        
        c = 0
        for x in range(n):
            for y in range(m):
                c += vis[x][y]
                vis[x][y] = 0
        
        if c == target:
            if saved_dir == 0: ans.append(f'W{saved_x + 1}')
            elif saved_dir == 1: ans.append(f'N{saved_y + 1}')
            elif saved_dir == 2: ans.append(f'E{saved_x + 1}')
            else: ans.append(f'S{saved_y + 1}')

    vis = [[0] * m for _ in range(n)]
    for i in range(m):
        check(0, i, 1)
        check(n - 1, i, 3)

    for i in range(n):
        check(i, 0, 0)
        check(i, m - 1, 2)
        
    print(len(ans))
    if ans: print(' '.join(ans))