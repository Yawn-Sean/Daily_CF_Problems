# Submission link: https://codeforces.com/contest/1970/submission/319959286
def main():
    n, k = MII()

    ss = LII()
    ls = LII()

    grid = [[0, 0], [0, 0]]

    for i in range(n):
        grid[0][0] = (grid[0][0] + (ls[i] + ss[i]) * ss[i]) % mod
        grid[0][1] = (grid[0][1] + (ls[i] + ss[i]) * ls[i]) % mod
        grid[1][0] = (grid[1][0] + ss[i] * ss[i]) % mod
        grid[1][1] = (grid[1][1] + ss[i] * ls[i]) % mod

    total_s = sum(ss) % mod
    total_l = sum(ls) % mod

    res = matrix_pow(grid, k - 1)

    ans = 0
    ans += (ss[0] * res[0][0] + ls[0] * res[1][0]) * (total_s + total_l)
    ans += (ss[0] * res[0][1] + ls[0] * res[1][1]) * total_s

    print(ans % mod)