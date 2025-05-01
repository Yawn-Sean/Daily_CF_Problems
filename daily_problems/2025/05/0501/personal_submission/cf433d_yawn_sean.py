# Submission link: https://codeforces.com/contest/433/submission/317888932
def main():
    n, m, q = MII()
    grid = [LII() for _ in range(n)]

    left = [[0] * m for _ in range(n)]
    right = [[0] * m for _ in range(n)]
    up = [[0] * m for _ in range(n)]
    down = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if grid[i][j]:
                left[i][j] = 1
                right[i][j] = 1
                up[i][j] = 1
                down[i][j] = 1

    for i in range(n):
        for j in range(m):
            if grid[i][j]:
                if j: left[i][j] += left[i][j - 1]
                if i: up[i][j] += up[i - 1][j]

    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            if grid[i][j]:
                if j + 1 < m: right[i][j] += right[i][j + 1]
                if i + 1 < n: down[i][j] += down[i + 1][j]

    outs = []

    for _ in range(q):
        op, x, y = GMI()
        if op:
            ans = 0
            
            l, r = x, x
            cur = left[x][y]
            
            while True:
                ans = fmax(ans, cur * (r - l + 1))
                if r - l == n - 1: break
                if l == 0:
                    r += 1
                    cur = fmin(cur, left[r][y])
                elif r == n - 1:
                    l -= 1
                    cur = fmin(cur, left[l][y])
                elif left[l - 1][y] > left[r + 1][y]:
                    l -= 1
                    cur = fmin(cur, left[l][y])
                else:
                    r += 1
                    cur = fmin(cur, left[r][y])
            
            l, r = x, x
            cur = right[x][y]
            
            while True:
                ans = fmax(ans, cur * (r - l + 1))
                if r - l == n - 1: break
                if l == 0:
                    r += 1
                    cur = fmin(cur, right[r][y])
                elif r == n - 1:
                    l -= 1
                    cur = fmin(cur, right[l][y])
                elif right[l - 1][y] > right[r + 1][y]:
                    l -= 1
                    cur = fmin(cur, right[l][y])
                else:
                    r += 1
                    cur = fmin(cur, right[r][y])
            
            l, r = y, y
            cur = up[x][y]
            
            while True:
                ans = fmax(ans, cur * (r - l + 1))
                if r - l == m - 1: break
                if l == 0:
                    r += 1
                    cur = fmin(cur, up[x][r])
                elif r == m - 1:
                    l -= 1
                    cur = fmin(cur, up[x][l])
                elif up[x][l - 1] > up[x][r + 1]:
                    l -= 1
                    cur = fmin(cur, up[x][l])
                else:
                    r += 1
                    cur = fmin(cur, up[x][r])
            
            l, r = y, y
            cur = down[x][y]
            
            while True:
                ans = fmax(ans, cur * (r - l + 1))
                if r - l == m - 1: break
                if l == 0:
                    r += 1
                    cur = fmin(cur, down[x][r])
                elif r == m - 1:
                    l -= 1
                    cur = fmin(cur, down[x][l])
                elif down[x][l - 1] > down[x][r + 1]:
                    l -= 1
                    cur = fmin(cur, down[x][l])
                else:
                    r += 1
                    cur = fmin(cur, down[x][r])
            
            outs.append(ans)
        else:
            grid[x][y] ^= 1
            
            for i in range(m):
                if grid[x][i]:
                    left[x][i] = 1
                    if i: left[x][i] += left[x][i - 1]
                else:
                    left[x][i] = 0
            
            for i in range(m - 1, -1, -1):
                if grid[x][i]:
                    right[x][i] = 1
                    if i + 1 < m: right[x][i] += right[x][i + 1]
                else:
                    right[x][i] = 0
            
            for i in range(n):
                if grid[i][y]:
                    up[i][y] = 1
                    if i: up[i][y] += up[i - 1][y]
                else:
                    up[i][y] = 0
            
            for i in range(n - 1, -1, -1):
                if grid[i][y]:
                    down[i][y] = 1
                    if i + 1 < n: down[i][y] += down[i + 1][y]
                else:
                    down[i][y] = 0

    print('\n'.join(map(str, outs)))