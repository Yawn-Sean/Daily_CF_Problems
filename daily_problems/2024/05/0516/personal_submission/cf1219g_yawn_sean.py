# Submission link: https://codeforces.com/contest/1219/submission/261114593
def main():
    n, m = MII()
    grid = [LII() for _ in range(n)]

    if max(n, m) <= 4:
        print(sum(sum(x) for x in grid))
        exit()

    rows = [0] * n
    cols = [0] * m

    for i in range(n):
        for j in range(m):
            rows[i] += grid[i][j]
            cols[j] += grid[i][j]

    def large2(iter):
        v1, v2 = 0, 0
        for x in iter:
            if x >= v1: v1, v2 = x, v1
            elif x > v2: v2 = x
        return v1 + v2

    def large3(iter):
        v1, v2, v3 = 0, 0, 0
        for x in iter:
            if x >= v1: v1, v2, v3 = x, v1, v2
            elif x >= v2: v2, v3 = x, v2
            elif x > v3: v3 = x
        return v1 + v2 + v3

    def large4(iter):
        v1, v2, v3, v4 = 0, 0, 0, 0
        for x in iter:
            if x >= v1: v1, v2, v3, v4 = x, v1, v2, v3
            elif x >= v2: v2, v3, v4 = x, v2, v3
            elif x >= v3: v3, v4 = x, v3
            elif x > v4: v4 = x
        return v1 + v2 + v3 + v4

    def fmax(x, y):
        return x if x > y else y

    ans = fmax(large4(rows), large4(cols))

    for i in range(n):
        ans = fmax(ans, rows[i] + large3(cols[j] - grid[i][j] for j in range(m)))

    for j in range(m):
        ans = fmax(ans, cols[j] + large3(rows[i] - grid[i][j] for i in range(n)))

    if n < m:
        for i1 in range(n):
            for i2 in range(i1):
                ans = fmax(ans, rows[i1] + rows[i2] + large2(cols[j] - grid[i1][j] - grid[i2][j] for j in range(m)))
    else:
        for j1 in range(m):
            for j2 in range(j1):
                ans = fmax(ans, cols[j1] + cols[j2] + large2(rows[i] - grid[i][j1] - grid[i][j2] for i in range(n)))

    print(ans)