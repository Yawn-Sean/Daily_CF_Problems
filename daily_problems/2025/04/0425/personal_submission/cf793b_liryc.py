'''
https://codeforces.com/problemset/submission/793/317152402
'''
# BFS + deque
def solve(n: int, m: int, grid: list[str]) -> bool:
    dq = deque()
    vis = [[[-1] * 2 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'S':
                dq.append((i, j, 0, 0))
                dq.append((i, j, 1, 0))
                vis[i][j][0] = vis[i][j][1] = 0
                break
        if dq:
            break

    while dq:
        i, j, d, pt = dq.popleft()
        p = vis[i][j][d]
        if p != pt:
            continue
        if d == 0:
            for ni in [i - 1, i + 1]:
                if 0 <= ni < n:
                    if grid[ni][j] == 'T':
                        return True
                    elif grid[ni][j] == '.' and (vis[ni][j][d] < 0 or vis[ni][j][d] > p):
                        vis[ni][j][d] = p
                        dq.appendleft((ni, j, d, p))
            if p < 2 and (vis[i][j][1] < 0 or vis[i][j][1] > p + 1):
                vis[i][j][1] = p + 1
                dq.append((i, j, 1, p + 1))
        else: 
            for nj in [j - 1, j + 1]:
                if 0 <= nj < m:
                    if grid[i][nj] == 'T':
                        return True
                    elif grid[i][nj] == '.' and (vis[i][nj][d] < 0 or vis[i][nj][d] > p):
                        vis[i][nj][d] = p
                        dq.appendleft((i, nj, d, p))
            if p < 2 and (vis[i][j][0] < 0 or vis[i][j][0] > p + 1):
                vis[i][j][0] = p + 1
                dq.append((i, j, 0, p + 1))
    return False
