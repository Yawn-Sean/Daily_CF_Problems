def main():
    n, m = map(int, input().split())
    g = [list(map(int, input().split())) for _ in range(n)]

    smaller = [[0] * m for _ in range(n)]
    larger = [[0] * m for _ in range(n)]
    for i in range(n):
        row = sorted(set(g[i]))
        k = len(row)
        d = {v: i for i, v in enumerate(row)}
        for j in range(m):
            smaller[i][j] = d[g[i][j]]
            larger[i][j] = k - 1 - d[g[i][j]]

    for j in range(m):
        col = sorted({g[i][j] for i in range(n)})
        k = len(col)
        d = {v: i for i, v in enumerate(col)}
        for i in range(n):
            smaller[i][j] = max(smaller[i][j], d[g[i][j]])
            larger[i][j] = max(larger[i][j], k - 1 - d[g[i][j]])

    for i in range(n):
        for j in range(m):
            smaller[i][j] += larger[i][j] + 1

    print('\n'.join(' '.join(map(str, x)) for x in smaller))

main()