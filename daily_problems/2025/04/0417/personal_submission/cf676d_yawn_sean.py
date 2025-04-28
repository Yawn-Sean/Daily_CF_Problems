# Submission link: https://codeforces.com/contest/676/submission/315898253
def main():
    d = {}
    d['+'] = 0
    d['-'] = 1
    d['|'] = 2
    d['^'] = 3
    d['>'] = 4
    d['v'] = 5
    d['<'] = 6
    d['U'] = 7
    d['R'] = 8
    d['D'] = 9
    d['L'] = 10
    d['*'] = 11

    rotate = [0, 2, 1, 4, 5, 6, 3, 8, 9, 10, 7, 11]

    moves = [[0] * 12 for _ in range(4)]

    for i in range(12):
        moves[0][i] = i

    for i in range(1, 4):
        for j in range(12):
            moves[i][j] = rotate[moves[i - 1][j]]

    tmp = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    dirs = [15, 10, 5, 1, 2, 4, 8, 14, 13, 11, 7, 0]
    bits = [[j for j in range(4) if i >> j & 1] for i in range(16)]

    n, m = MII()
    grid = [[d[x] for x in I()] for _ in range(n)]

    sx, sy = GMI()
    tx, ty = GMI()

    def f(x, y):
        return x * m + y

    def g(msk, status):
        return msk * 4 + status

    dis = [[-1] * (n * m) for _ in range(4)]
    dis[0][f(sx, sy)] = 0

    que = [g(f(sx, sy), 0)]

    for u in que:
        msk, status = divmod(u, 4)
        x, y = divmod(msk, m)
        
        if x == tx and y == ty:
            exit(print(dis[status][f(x, y)]))
        
        for bit in bits[dirs[moves[status][grid[x][y]]]]:
            dx, dy = tmp[bit]
            nx = x + dx
            ny = y + dy
            
            if 0 <= nx < n and 0 <= ny < m and dis[status][f(nx, ny)] == -1 and dirs[moves[status][grid[nx][ny]]] >> (bit ^ 2) & 1:
                dis[status][f(nx, ny)] = dis[status][f(x, y)] + 1
                que.append(g(f(nx, ny), status))
        
        nstatus = (status + 1) % 4
        
        if dis[nstatus][f(x, y)] == -1:
            dis[nstatus][f(x, y)] = dis[status][f(x, y)] + 1
            que.append(g(f(x, y), nstatus))

    print(-1)