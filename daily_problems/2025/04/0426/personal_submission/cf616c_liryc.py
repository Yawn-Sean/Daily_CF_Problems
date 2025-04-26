'''
https://codeforces.com/problemset/submission/616/317268838
'''
# BFS Fill Grid
def solve(n: int, m: int, grid: list[str]) -> list[str]:
    sa = [[0] * m for _ in range(n)]
    op = [[0] * m for _ in range(n)]

    def bfsfill(x, y):
        nonlocal n, m, grid, sa, op
        p = x * m + y
        sa[x][y] = -1
        dq = [(x, y)]
        i = 0
        while i < len(dq):
            x0, y0 = dq[i]
            i += 1
            for e1, e2 in pairwise([0, 1, 0, -1, 0]):
                x1, y1 = x0 + e1, y0 + e2
                if 0 <= x1 < n and 0 <= y1 < m and grid[x1][y1] == '.' and sa[x1][y1] == 0:
                    sa[x1][y1] = -1
                    dq.append((x1, y1))
        c = len(dq)
        for x, y in dq:
            sa[x][y] = c
            op[x][y] = p

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '.' and sa[i][j] == 0:
                bfsfill(i, j)
    for i in range(n):
        for j in range(m):
            if grid[i][j] == '*':
                ps = set()
                c = 1
                for e1, e2 in pairwise([0, 1, 0, -1, 0]):
                    i1, j1 = i + e1, j + e2
                    if 0 <= i1 < n and 0 <= j1 < m and grid[i1][j1] == '.' and not op[i1][j1] in ps:
                        ps.add(op[i1][j1])
                        c += sa[i1][j1]
                sa[i][j] = c % 10
    return [''.join((str(sa[i][j]) if grid[i][j] == '*' else '.') for j in range(m)) for i in range(n)]