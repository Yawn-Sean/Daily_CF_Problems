# Submission link: https://codeforces.com/contest/372/submission/292260110
def main():
    n, m, q = MII()
    grid = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n):
        s = I()
        for j in range(m):
            grid[i + 1][j + 1] = int(s[j])

    for i in range(n):
        for j in range(m + 1):
            grid[i + 1][j] += grid[i][j]

    for i in range(n + 1):
        for j in range(m):
            grid[i][j + 1] += grid[i][j]

    def f(i1, i2, j1, j2):
        return ((i1 * n + i2) * m + j1) * m + j2 

    pref = [0] * (n * n * m * m)

    for i2 in range(n):
        for i1 in range(i2 + 1):
            for j2 in range(m):
                for j1 in range(j2 + 1):
                    if grid[i2 + 1][j2 + 1] - grid[i2 + 1][j1] - grid[i1][j2 + 1] + grid[i1][j1] == 0:
                        pref[f(n - 1 - i1, i2, m - 1 - j1, j2)] = 1

    for i1 in range(n - 1):
        for i2 in range(n):
            for j1 in range(m):
                for j2 in range(m):
                    pref[f(i1 + 1, i2, j1, j2)] += pref[f(i1, i2, j1, j2)]

    for i1 in range(n):
        for i2 in range(n - 1):
            for j1 in range(m):
                for j2 in range(m):
                    pref[f(i1, i2 + 1, j1, j2)] += pref[f(i1, i2, j1, j2)]

    for i1 in range(n):
        for i2 in range(n):
            for j1 in range(m - 1):
                for j2 in range(m):
                    pref[f(i1, i2, j1 + 1, j2)] += pref[f(i1, i2, j1, j2)]

    for i1 in range(n):
        for i2 in range(n):
            for j1 in range(m):
                for j2 in range(m - 1):
                    pref[f(i1, i2, j1, j2 + 1)] += pref[f(i1, i2, j1, j2)]

    outs = []
    for _ in range(q):
        i1, j1, i2, j2 = GMI()
        outs.append(pref[f(n - 1 - i1, i2, m - 1 - j1, j2)])

    print('\n'.join(map(str, outs)))