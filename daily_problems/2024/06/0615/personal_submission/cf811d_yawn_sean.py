# Submission link: https://codeforces.com/contest/811/submission/265821578
def main():
    n, m = MII()
    grid = [I() for _ in range(n)]

    vis = [[0] * m for _ in range(n)]
    vis[0][0] = 1

    prev = [[None] * m for _ in range(n)]

    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    endx, endy = -1, -1

    stack = [(0, 0)]
    while stack:
        x, y = stack.pop()
        if grid[x][y] == 'F':
            endx, endy = x, y
        for dx, dy in dirs:
            if 0 <= x + dx < n and 0 <= y + dy < m and grid[x+dx][y+dy] != '*' and vis[x+dx][y+dy] == 0:
                vis[x+dx][y+dy] = 1
                prev[x+dx][y+dy] = (x, y)
                stack.append((x+dx, y+dy))

    steps = [(endx, endy)]

    while True:
        x, y = steps[-1]
        if prev[x][y] is None: break
        steps.append(prev[x][y])

    steps.reverse()

    ud = 'UD'
    lr = 'LR'

    f_ud = False
    f_lr = False

    def op(c):
        print(c, flush=True)
        return GMI()

    k = len(steps)
    for i in range(k - 1):
        dx, dy = steps[i+1][0] - steps[i][0], steps[i+1][1] - steps[i][1]
        if dx == 0:
            if not f_lr:
                f_lr = True
                nx, ny = op('L')
                if ny == steps[i+1][1]: lr = 'RL'
                else: op('R')
            else:
                if dy > 0: op(lr[1])
                else: op(lr[0])
        else:
            if not f_ud:
                f_ud = True
                nx, ny = op('U')
                if nx == steps[i+1][0]: ud = 'DU'
                else: op('D')
            else:
                if dx > 0: op(ud[1])
                else: op(ud[0])