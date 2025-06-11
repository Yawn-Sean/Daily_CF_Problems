'''
https://codeforces.com/problemset/submission/1137/303891514
'''
def solve(n: int, m: int, grid: list[list[int]]) -> list[str]:
    smaller = [[0] * m for _ in range(n)]
    larger = [[0] * m for _ in range(n)]

    for i in range(n):
        row = sorted(set(grid[i]))
        k = len(row)
        d = {v: i for i, v in enumerate(row)}
        for j in range(m):
            smaller[i][j] = d[grid[i][j]]
            larger[i][j] = k - 1 - d[grid[i][j]]

    for j in range(m):
        col = sorted({grid[i][j] for i in range(n)})
        k = len(col)
        d = {v: i for i, v in enumerate(col)}
        for i in range(n):
            smaller[i][j] = max(smaller[i][j], d[grid[i][j]])
            larger[i][j] = max(larger[i][j], k - 1 - d[grid[i][j]])

    for i in range(n):
        for j in range(m):
            smaller[i][j] += larger[i][j] + 1

    return [' '.join(map(str, r)) for r in smaller]
