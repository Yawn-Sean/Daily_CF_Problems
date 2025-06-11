n, m = MII()
cols = [0] * n
rows = [0] * n
rs = ls = 0

for _ in range(m):
    x, y = GMI()
    if cols[x] == 0:
        cols[x] = 1
        ls += 1
    if rows[y] == 0:
        rows[y] = 1
        rs += 1

f = [[0] * (n + 2) for _ in range(n + 2)]

for i in range(n, rs - 1, -1):
    for j in range(n, ls - 1, -1):
        if i == n and j == n:
            continue
        p1, p2, p3, p4 = i * j / (n * n), i * (n - j) / (n * n), (n - i) * j / (n * n), (n - i) * (n - j) / (n * n)
        f[i][j] = (1 + p2 * f[i][j + 1] + p3 * f[i + 1][j] + p4 * f[i + 1][j + 1]) / (1 - p1)

print(f[rs][ls])
