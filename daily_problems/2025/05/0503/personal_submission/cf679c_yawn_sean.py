# Submission link: https://codeforces.com/contest/679/submission/318164193
def main():
    n, k = MII()
    grid = [[1 if c == '.' else 0 for c in I()] for _ in range(n)]

    acc = [[0] * (n + 1) for _ in range(n + 1)]

    for i in range(n):
        for j in range(n):
            if grid[i][j] == 0:
                acc[i + 1][j + 1] = 1

    for i in range(n):
        for j in range(n + 1):
            acc[i + 1][j] += acc[i][j]

    for i in range(n + 1):
        for j in range(n):
            acc[i][j + 1] += acc[i][j]

    group = [[-1] * n for _ in range(n)]
    group_cnt = [0] * (n * n)
    re_calc = [[0] * (n + 1) for _ in range(n + 1)]

    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    def f(x, y):
        return x * n + y

    for i in range(n):
        for j in range(n):
            if grid[i][j] and group[i][j] == -1:
                group_id = f(i, j)
                sz = 1
                
                mxx, mnx = i, i
                mxy, mny = j, j
                
                stk = [f(i, j)]
                group[i][j] = group_id
                
                while stk:
                    x, y = divmod(stk.pop(), n)
                    mxx = fmax(mxx, x)
                    mnx = fmin(mnx, x)
                    mxy = fmax(mxy, y)
                    mny = fmin(mny, y)
                    for dx, dy in dirs:
                        if 0 <= x + dx < n and 0 <= y + dy < n and group[x + dx][y + dy] == -1 and grid[x + dx][y + dy]:
                            group[x + dx][y + dy] = group_id
                            stk.append(f(x + dx, y + dy))
                            sz += 1

                group_cnt[f(i, j)] = sz
                
                if mxx - mnx < k and mxy - mny < k:
                    lx = fmax(0, mxx - k + 1)
                    rx = fmin(mnx, n - k)
                    
                    ly = fmax(0, mxy - k + 1)
                    ry = fmin(mny, n - k)

                    re_calc[lx][ly] += sz
                    re_calc[lx][ry + 1] -= sz
                    re_calc[rx + 1][ly] -= sz
                    re_calc[rx + 1][ry + 1] += sz

    for i in range(n):
        for j in range(n + 1):
            re_calc[i + 1][j] += re_calc[i][j]

    for i in range(n + 1):
        for j in range(n):
            re_calc[i][j + 1] += re_calc[i][j]

    vis = [0] * (n * n)

    ans = 0

    for i in range(n - k + 1):
        for j in range(n - k + 1):
            res = 0
            tmp = []
            
            if i:
                for nj in range(j, j + k):
                    if grid[i - 1][nj] and not vis[group[i - 1][nj]]:
                        vis[group[i - 1][nj]] = 1
                        tmp.append(group[i - 1][nj])
                        res += group_cnt[group[i - 1][nj]]
            
            if i + k < n:
                for nj in range(j, j + k):
                    if grid[i + k][nj] and not vis[group[i + k][nj]]:
                        vis[group[i + k][nj]] = 1
                        tmp.append(group[i + k][nj])
                        res += group_cnt[group[i + k][nj]]
            
            if j:
                for ni in range(i, i + k):
                    if grid[ni][j - 1] and not vis[group[ni][j - 1]]:
                        vis[group[ni][j - 1]] = 1
                        tmp.append(group[ni][j - 1])
                        res += group_cnt[group[ni][j - 1]]
            
            if j + k < n:
                for ni in range(i, i + k):
                    if grid[ni][j + k] and not vis[group[ni][j + k]]:
                        vis[group[ni][j + k]] = 1
                        tmp.append(group[ni][j + k])
                        res += group_cnt[group[ni][j + k]]
            
            res += acc[i + k][j + k] - acc[i][j + k] - acc[i + k][j] + acc[i][j]
            res += re_calc[i][j]
            
            ans = fmax(ans, res)
            
            for x in tmp:
                vis[x] = 0

    print(ans)