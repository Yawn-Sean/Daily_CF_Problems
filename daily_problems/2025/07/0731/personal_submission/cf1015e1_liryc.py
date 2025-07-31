'''
https://codeforces.com/contest/1015/submission/331718581
https://codeforces.com/contest/1015/submission/331718514
'''
# 前缀和 / 差分

# grid has changed to 0-1 matrix
def solve(n: int, m: int, grid: list[list[int]]) -> list[str]:
    px = [[0] * m for _ in range(n)]
    sx = [[0] * m for _ in range(n)]
    py = [[0] * n for _ in range(m)]
    sy = [[0] * n for _ in range(m)]

    # preprocess
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 0:
                px[i][j] = py[j][i] = 0
            else:
                px[i][j] = (0 if j == 0 else px[i][j - 1]) + 1
                py[j][i] = (0 if i == 0 else py[j][i - 1]) + 1

    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            if grid[i][j] == 0:
                sx[i][j] = sy[j][i] = 0
            else:
                sx[i][j] = (0 if j == m - 1 else sx[i][j + 1]) + 1
                sy[j][i] = (0 if i == n - 1 else sy[j][i + 1]) + 1

    # try add the asterisks
    dx = [[0] * (m + 1) for _ in range(n)]
    dy = [[0] * (n + 1) for _ in range(m)]
    ans = []
    for i in range(n):
        for j in range(m):   
            if grid[i][j]:
                s = min(px[i][j], sx[i][j], py[j][i], sy[j][i])
                if s > 1:
                    ans.append(f"{i + 1} {j + 1} {s - 1}")
                    dx[i][j - s + 1] += 1
                    dx[i][j + s] -= 1
                    dy[j][i - s + 1] += 1
                    dy[j][i + s] -= 1

    # verify answer
    ry = [0] * m
    for i in range(n):
        sm = 0
        for j in range(m):
            sm += dx[i][j]
            ry[j] += dy[j][i]
            if grid[i][j] and not (sm or ry[j]):
                return ["-1"] 
    return ans
