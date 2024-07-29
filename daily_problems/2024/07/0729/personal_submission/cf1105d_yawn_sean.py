# Submission link: https://codeforces.com/contest/1105/submission/273256234
def main():
    n, m, p = MII()
    speed = LII()

    grid = [list(I()) for _ in range(n)]

    def f(x, y):
        return x * m + y

    cur = [[] for _ in range(p + 1)]
    notes = [str(i) for i in range(p + 1)]
    cnt = [0] * (p + 1)

    for i in range(n):
        for j in range(m):
            if '1' <= grid[i][j] <= '9':
                v = int(grid[i][j])
                cur[v].append(f(i, j))
                cnt[v] += 1

    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    while True:
        flg = False
        for i in range(1, p + 1):
            for _ in range(speed[i-1]):
                ncur = []
                for msk in cur[i]:
                    x, y = divmod(msk, m)
                    for dx, dy in dirs:
                        if 0 <= x + dx < n and 0 <= y + dy < m and grid[x+dx][y+dy] == '.':
                            grid[x+dx][y+dy] = notes[i]
                            cnt[i] += 1
                            ncur.append(f(x + dx, y + dy))
                cur[i] = ncur
                if len(cur[i]) == 0:
                    break
            
            if len(cur[i]):
                flg = True
        if not flg: break

    print(*cnt[1:])