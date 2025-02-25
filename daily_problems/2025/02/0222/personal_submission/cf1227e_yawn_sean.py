# Submission link: https://codeforces.com/contest/1227/submission/307208232
def main():
    n, m = MII()
    grid = []

    for _ in range(n):
        grid.extend(1 if c == 'X' else 0 for c in I())

    def p(i, j):
        return i * m + j

    def f(i, j):
        return i * (m + 1) + j

    acc = [0] * ((n + 1) * (m + 1))

    for i in range(n):
        for j in range(m):
            acc[f(i + 1, j + 1)] = grid[p(i, j)]

    for i in range(n):
        for j in range(m + 1):
            acc[f(i + 1, j)] += acc[f(i, j)]

    for i in range(n + 1):
        for j in range(m):
            acc[f(i, j + 1)] += acc[f(i, j)]

    ngrid = [0] * ((n + 1) * (m + 1))

    l, r = 0, (fmin(n, m) - 1) // 2

    while l <= r:
        mid = (l + r) // 2
        
        target = (2 * mid + 1) * (2 * mid + 1)
        for i in range(mid, n - mid):
            for j in range(mid, m - mid):
                if acc[f(i + mid + 1, j + mid + 1)] - acc[f(i - mid, j + mid + 1)] - acc[f(i + mid + 1, j - mid)] + acc[f(i - mid, j - mid)] == target:
                    ngrid[f(i - mid, j - mid)] += 1
                    ngrid[f(i - mid, j + mid + 1)] -= 1
                    ngrid[f(i + mid + 1, j - mid)] -= 1
                    ngrid[f(i + mid + 1, j + mid + 1)] += 1
        
        for i in range(n):
            for j in range(m + 1):
                ngrid[f(i + 1, j)] += ngrid[f(i, j)]
        
        for i in range(n + 1):
            for j in range(m):
                ngrid[f(i, j + 1)] += ngrid[f(i, j)]
        
        flg = True
        for i in range(n):
            for j in range(m):
                if (grid[p(i, j)] == 0) != (ngrid[f(i, j)] == 0):
                    flg = False
                ngrid[f(i, j)] = 0 
        
        if flg: l = mid + 1
        else: r = mid - 1

    print(r)

    ans = [0] * (n * m)
    target = (2 * r + 1) * (2 * r + 1)

    for i in range(r, n - r):
        for j in range(r, m - r):
            if acc[f(i + r + 1, j + r + 1)] - acc[f(i - r, j + r + 1)] - acc[f(i + r + 1, j - r)] + acc[f(i - r, j - r)] == target:
                ans[p(i, j)] = 1

    print('\n'.join(''.join('X' if ans[p(i, j)] else '.' for j in range(m)) for i in range(n)))