def solve() -> None:
    N, M = map(int, input().split())
    g = [input() for _ in range(N)]
    vis = [[False] * M for _ in range(N)]
    vis[0][0] = True
    dir = [-1, 0, 1, 0, -1]

    pre = [[None] * M for _ in range(N)]
    q = [(0, 0)] * (N * M)
    f, b = 0, 1
    edx = edy = 0
    while b - f:
        x, y = q[f]
        f += 1
        if g[x][y] == 'F': # get it
            edx, edy = x, y

        for k in range(4):
            nx, ny = x + dir[k], y + dir[k + 1]
            if nx < 0 or ny < 0 or nx >= N or ny >= M or g[nx][ny] == '*' or vis[nx][ny]:
                continue
            vis[nx][ny] = True
            pre[nx][ny] = (x, y)
            q[b] = (nx, ny)
            b += 1

    path = [(edx, edy)]

    while pre[path[-1][0]][path[-1][1]]:
        path.append(pre[path[-1][0]][path[-1][1]])
    path.reverse()

    ud = ['U', 'D']
    lr = ['L', 'R']
    j = len(path)
    xok = yok = False
    for i in range(j - 1):
        dx, dy = path[i + 1][0] - path[i][0], path[i + 1][1] - path[i][1]
        if not dx:
            if yok:
                print(lr[1 if dy > 0 else 0], flush=True)
                input()
            else:   #第一次往右跑
                print('L', flush=True)
                nx, ny = map(int, input().split())
                nx -= 1
                ny -= 1
                if ny == path[i + 1][1]:
                    lr[0], lr[1] = lr[1], lr[0]
                else:
                    print('R', flush=True)
                    input()
                yok = True
        if not dy:
            if xok:
                print(ud[1 if dx > 0 else 0], flush=True)
                input()
            else:   #第一次往下跑
                print('U', flush=True)
                nx, ny = map(int, input().split())
                nx -= 1
                ny -= 1
                if nx == path[i + 1][0]:
                    ud[0], ud[1] = ud[1], ud[0]
                else:
                    print('D', flush=True)
                    input()
                xok = True

solve()