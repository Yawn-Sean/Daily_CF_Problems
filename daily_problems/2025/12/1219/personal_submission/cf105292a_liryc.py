'''
https://codeforces.com/gym/105292/submission/354040295
'''
# grid fill: fill 'L' if neither left nor up hv light
def solve(n: int, m: int, grid: list[str]) -> list[str]:
    vis = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if grid[i][j] != '#':
                if j and vis[i][j - 1] & 5:
                    vis[i][j] |= 1
                if i and vis[i - 1][j] & 6:
                    vis[i][j] |= 2
                if vis[i][j] == 0:
                    vis[i][j] = 4
    return [''.join('#' if grid[i][j] == '#' else 'L' if vis[i][j] == 4 else '.' for j in range(m)) for i in range(n)]
