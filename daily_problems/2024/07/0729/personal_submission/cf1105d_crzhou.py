from collections import deque

N = 1005
K = 15
directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

class Node:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def not_empty(queues):
    for q in queues:
        if q:
            return True
    return False

def bfs():
    while not_empty(q):
        for i in range(1, k + 1):
            for _ in range(a[i]):
                if not q[i]:
                    break
                nowx, nowy = q[i][0].x, q[i][0].y
                while q[i]:
                    x, y = q[i][0].x, q[i][0].y
                    if dis[nowx][nowy] != dis[x][y]:
                        break
                    q[i].popleft()
                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy
                        if nx < 1 or nx > n or ny < 1 or ny > m:
                            continue
                        if grid[nx][ny] != '.' or dis[nx][ny]:
                            continue

                        grid[nx][ny] = str(i)
                        ans[i] += 1
                        q[i].append(Node(nx, ny))
                        dis[nx][ny] = dis[x][y] + 1

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    idx = 0
    n = int(data[idx])
    idx += 1
    m = int(data[idx])
    idx += 1
    k = int(data[idx])
    idx += 1

    a = [0] * (k + 1)
    for i in range(1, k + 1):
        a[i] = int(data[idx])
        idx += 1

    grid = [[''] * (m + 1) for _ in range(n + 1)]
    dis = [[0] * (m + 1) for _ in range(n + 1)]
    ans = [0] * (k + 1)
    q = [deque() for _ in range(K)]

    for i in range(1, n + 1):
        line = data[idx]
        idx += 1
        for j in range(1, m + 1):
            grid[i][j] = line[j - 1]
            if '1' <= grid[i][j] <= '9':
                pos = int(grid[i][j])
                q[pos].append(Node(i, j))
                ans[pos] += 1

    bfs()

    print(' '.join(map(str, ans[1:])))
