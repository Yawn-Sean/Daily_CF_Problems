# Submission link: https://codeforces.com/contest/847/submission/313187080
def main():
    n, m, q, p = MII()
    grid = [I() for _ in range(n)]
    vis = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '*':
                vis[i][j] = -1

    ans = [[0] * m for _ in range(n)]
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    for i in range(n):
        for j in range(m):
            if grid[i][j].isupper():
                que = [i * m + j]
                vis[i][j] = (ord(grid[i][j]) - ord('A') + 1) * q
                
                for u in que:
                    x, y = divmod(u, m)
                    ans[x][y] += vis[x][y]
                    
                    for dx, dy in dirs:
                        nx = x + dx
                        ny = y + dy
                        if 0 <= nx < n and 0 <= ny < m and vis[nx][ny] == 0:
                            vis[nx][ny] = vis[x][y] // 2
                            if vis[nx][ny]:
                                que.append(nx * m + ny)
                
                for u in que:
                    x, y = divmod(u, m)
                    vis[x][y] = 0

    res = 0
    for i in range(n):
        for j in range(m):
            if ans[i][j] > p:
                res += 1

    print(res)