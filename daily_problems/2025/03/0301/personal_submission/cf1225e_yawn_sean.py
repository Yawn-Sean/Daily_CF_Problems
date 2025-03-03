# Submission link: https://codeforces.com/contest/1225/submission/308427808
def main():
    n, m = MII()

    grid = [I() for _ in range(n)]
    acc_h = [[0] * (m + 1) for _ in range(n)]
    acc_v = [[0] * m for _ in range(n + 1)]

    if grid[0][0] == 'R' or grid[n - 1][m - 1] == 'R':
        exit(print(0))

    if n == 1 and m == 1:
        exit(print(1))

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'R':
                acc_h[i][j] = 1
                acc_v[i][j] = 1

    for i in range(n - 2, -1, -1):
        for j in range(m):
            acc_v[i][j] += acc_v[i + 1][j]

    for i in range(n):
        for j in range(m - 2, -1, -1):
            acc_h[i][j] += acc_h[i][j + 1]

    mod = 10 ** 9 + 7

    diff_h = [[0] * (m + 1) for _ in range(n)]
    diff_v = [[0] * m for _ in range(n + 1)]

    cur_h = [0] * n
    cur_v = [0] * m

    diff_h[0][0] = 1
    diff_h[0][1] = -1

    diff_v[0][0] = 1
    diff_v[1][0] = -1

    for i in range(n):
        for j in range(m):
            cur_h[i] += diff_h[i][j]
            cur_h[i] %= mod
            cur_v[j] += diff_v[i][j]
            cur_v[j] %= mod
            
            diff_h[i][j + 1] += cur_v[j]
            diff_h[i][j + 1] %= mod
            diff_h[i][m - acc_h[i][j + 1]] -= cur_v[j]
            diff_h[i][m - acc_h[i][j + 1]] %= mod
            
            diff_v[i + 1][j] += cur_h[i]
            diff_v[i + 1][j] %= mod
            diff_v[n - acc_v[i + 1][j]][j] -= cur_h[i]
            diff_v[n - acc_v[i + 1][j]][j] %= mod

    print((cur_h[-1] + cur_v[-1]) % mod)