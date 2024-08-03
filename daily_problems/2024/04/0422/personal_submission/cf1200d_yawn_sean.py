# Submission link: https://codeforces.com/contest/1200/submission/257674614
def main():
    n, k = MII()
    grid = [I() for _ in range(n)]

    benchmark = 0
    diff = [[0] * (n + 1) for _ in range(n + 1)]

    for i in range(n):
        mi = n
        ma = -1
        for j in range(n):
            if grid[i][j] == 'B':
                mi = min(mi, j)
                ma = max(ma, j)
        if mi > ma: benchmark += 1
        elif mi + k - 1 >= ma:
            xl = max(0, i - k + 1)
            xr = i
            yl = max(0, ma - k + 1)
            yr = mi
            diff[xl][yl] += 1
            diff[xr + 1][yl] -= 1
            diff[xl][yr + 1] -= 1
            diff[xr + 1][yr + 1] += 1

    for j in range(n):
        mi = n
        ma = -1
        for i in range(n):
            if grid[i][j] == 'B':
                mi = min(mi, i)
                ma = max(ma, i)
        if mi > ma: benchmark += 1
        elif mi + k - 1 >= ma:
            xl = max(0, ma - k + 1)
            xr = mi
            yl = max(0, j - k + 1)
            yr = j
            diff[xl][yl] += 1
            diff[xr + 1][yl] -= 1
            diff[xl][yr + 1] -= 1
            diff[xr + 1][yr + 1] += 1

    for i in range(n):
        for j in range(n + 1):
            diff[i+1][j] += diff[i][j]

    for i in range(n + 1):
        for j in range(n):
            diff[i][j+1] += diff[i][j]

    print(max(max(x) for x in diff) + benchmark)