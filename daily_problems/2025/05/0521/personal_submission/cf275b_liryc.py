'''
https://codeforces.com/problemset/submission/275/320599387
'''
# grid BFS
def solve(n: int, m: int, grid: list[list[str]]) -> bool:
    vis = [0] * n

    def vis_init():
        nonlocal vis, n
        vis = [0] * n

    def vis_set(i, j):
        nonlocal vis
        if vis[i] & 1 << j:
            return 0
        vis[i] |= 1 << j
        return 1

    def vis_check(i, j):
        nonlocal vis
        return vis[i] & 1 << j

    black_count = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'B':
                black_count += 1
    if black_count == n * m:
        return True

    di = [0, 1, 0, -1, 0]
    ta = [(1, 3), (0, 2), (1, 3), (0, 2)]
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'B':
                vis_init()
                dq = deque()
                for d in range(4):
                    dq.append((i, j, d))
                cells = vis_set(i, j)
                while dq:
                    x, y, d = dq.popleft()
                    turned = False
                    if d < 0: 
                        turned = True
                        nx, ny = x + di[~d], y + di[~d + 1]
                    else:
                        nx, ny = x + di[d], y + di[d + 1]
                    if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 'B':
                        cells += vis_set(nx, ny)
                        dq.appendleft((nx, ny, d))
                    if not turned:
                        for t in ta[d]:
                            dq.append((x, y, ~t))
                if cells != black_count:
                    return False
    return True
