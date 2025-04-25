# Submission link: https://codeforces.com/contest/793/submission/317115347
def main():
    n, m = MII()
    grid = [I() for _ in range(n)]
    sx, sy = -1, -1
    tx, ty = -1, -1

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'S':
                sx, sy = i, j
            if grid[i][j] == 'T':
                tx, ty = i, j

    check = [[1 if grid[i][j] == '*' else 0 for j in range(m)] for i in range(n)]

    def f(x1, y1, x2, y2):
        if x1 > x2:
            x1, x2 = x2, x1
        if y1 > y2:
            y1, y2 = y2, y1
        
        for i in range(x1, x2 + 1):
            for j in range(y1, y2 + 1):
                if check[i][j]:
                    return False
        return True

    for i in range(n):
        if f(sx, sy, i, sy) and f(i, sy, i, ty) and f(i, ty, tx, ty):
            exit(print('YES'))

    for i in range(m):
        if f(sx, sy, sx, i) and f(sx, i, tx, i) and f(tx, i, tx, ty):
            exit(print('YES'))

    print('NO')