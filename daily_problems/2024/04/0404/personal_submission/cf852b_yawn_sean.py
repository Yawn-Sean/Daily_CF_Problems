# Submission link: https://codeforces.com/contest/852/submission/254910034
def main():
    mod = 10 ** 9 + 7

    n, l, m = MII()

    start = LII()
    middle = LII()
    end = LII()

    cnt = [0] * m
    for x in middle:
        cnt[x % m] += 1

    grid = [[0] * m for _ in range(m)]
    for i in range(m):
        for j in range(m):
            grid[i][(i + j) % m] = cnt[j]

    origin = [[0] * m]
    for x in start:
        origin[0][x % m] += 1

    dp = matrix_mul(origin, matrix_pow(grid, l - 2))[0]

    ans = 0
    for i in range(n):
        ans += dp[(- middle[i] - end[i]) % m]
    print(ans % mod)