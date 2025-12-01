import sys
input = lambda: sys.stdin.readline().rstrip()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def sol() -> bool:
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]

    res = 0
    tmp = []

    for i in range(n):
        for j in range(m):
            res ^= a[i][j] & 1
            tmp.append([a[i][j], i, j])

    tmp = sorted(tmp)

    to_fill = [[-1] * m for _ in range(n)]
    for v, x, y in tmp:
        val = -1
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
            val = max(val, to_fill[nx][ny])
        to_fill[x][y] = val + 1
        res ^= (val + 1) & 1

    return res

MT = int(input())
for _ in range(MT):
    print("Yes" if sol() else "No")
