# 1 | 4
# ------
# 2 | 3
def CF429B():
    n, m = MII()
    g = [LII() for _ in range(n)]
    f1 = [[0] * (m + 2) for _ in range(n + 2)]
    f2 = [[0] * (m + 2) for _ in range(n + 2)]
    f3 = [[0] * (m + 2) for _ in range(n + 2)]
    f4 = [[0] * (m + 2) for _ in range(n + 2)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            f1[i][j] = fmax(f1[i - 1][j], f1[i][j - 1]) + g[i - 1][j - 1]
        for j in range(m, 0, -1):
            f4[i][j] = fmax(f4[i - 1][j], f4[i][j + 1]) + g[i - 1][j - 1]
    for i in range(n, 0, -1):
        for j in range(1, m + 1):
            f2[i][j] = fmax(f2[i + 1][j], f2[i][j - 1]) + g[i - 1][j - 1]
        for j in range(m, 0, -1):
            f3[i][j] = fmax(f3[i + 1][j], f3[i][j + 1]) + g[i - 1][j - 1]
    
    ans = 0
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            ans = fmax(ans, f1[i][j + 1] + f4[i + 1][j + 2] + f2[i + 1][j] + f3[i + 2][j + 1])
            ans = fmax(ans, f1[i + 1][j] + f4[i][j + 1] + f2[i + 2][j + 1] + f3[i + 1][j + 2])
    print(ans)
    