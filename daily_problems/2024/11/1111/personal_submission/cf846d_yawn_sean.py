# Submission link: https://codeforces.com/contest/846/submission/290938278
def main():
    inf = 2 * 10 ** 9

    n, m, k, q = MII()
    grid = [[inf] * (m + 1) for _ in range(n + 1)]

    for _ in range(q):
        x, y, t = MII()
        grid[x][y] = t

    pref = [[0] * (m + 1) for _ in range(n + 1)]
    l, r = 0, inf

    while l <= r:
        mid = (l + r) // 2
        
        for i in range(n + 1):
            for j in range(m + 1):
                pref[i][j] = 1 if grid[i][j] <= mid else 0
        
        for i in range(n + 1):
            for j in range(m):
                pref[i][j + 1] += pref[i][j]
        
        for i in range(n):
            for j in range(m + 1):
                pref[i + 1][j] += pref[i][j]
        
        f = False
        
        for i in range(n - k + 1):
            for j in range(m - k + 1):
                if pref[i + k][j + k] - pref[i][j + k] - pref[i + k][j] + pref[i][j] == k * k:
                    f = True

        if f:
            r = mid - 1
        else:
            l = mid + 1

    print(l if l < inf else -1)