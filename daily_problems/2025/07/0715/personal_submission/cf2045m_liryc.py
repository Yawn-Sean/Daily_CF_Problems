'''
https://codeforces.com/problemset/submission/2045/328992813
'''
# implementation
def solve(r: int, c: int, grid: list[str]) -> list[str]:
    ds = [0, 1, 0, -1, 0]
    starts = [((i, 0) for i in range(r)), ((0, j) for j in range(c)), ((i, c - 1) for i in range(r)), ((r - 1, j) for j in range(c))]
    numMirrors = sum(s.count('/') + s.count('\\') for s in grid)
    vis = [[0] * c for _ in range(r)]
    ans = []
    makestr = lambda d, x, y: f"{'WNES'[d]}{y + 1 if d & 1 else x + 1}"

    for di_start in range(4):
        for x_start, y_start in starts[di_start]:
            for i in range(r):
                vis[i][:] = repeat(0, c)
            n = 0 # number of mirrors hit
            x, y, di = x_start, y_start, di_start
            while 0 <= x < r and 0 <= y < c:
                if grid[x][y] != '.':
                    if vis[x][y] == 0:
                        vis[x][y] = 1
                        n += 1
                    di = di ^ 3 if grid[x][y] == '/' else di ^ 1
                x, y = x + ds[di], y + ds[di + 1]
            if n == numMirrors:
                ans.append(makestr(di_start, x_start, y_start))
    return ans
