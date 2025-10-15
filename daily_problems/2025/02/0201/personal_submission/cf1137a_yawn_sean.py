# Submission link: https://codeforces.com/contest/1137/submission/303850007
def main():
    n, m = MII()
    rnd = random.getrandbits(20)
    grid = [[x + rnd for x in MII()] for _ in range(n)]

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
            smaller[i][j] = fmax(smaller[i][j], d[grid[i][j]])
            larger[i][j] = fmax(larger[i][j], k - 1 - d[grid[i][j]])

    for i in range(n):
        for j in range(m):
            smaller[i][j] += larger[i][j] + 1

    print('\n'.join(' '.join(map(str, x)) for x in smaller))