# Submission link: https://codeforces.com/contest/1970/submission/319575774
def main():
    n, k = MII()
    ss = LII()
    ls = LII()

    for i in range(n):
        ss[i] += ls[i]

    grid = [[0] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            grid[i][j] = ss[i] * ss[j] - ls[i] * ls[j]

    res = matrix_pow(grid, k)

    print(sum(res[0]) % mod)