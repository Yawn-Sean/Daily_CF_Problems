import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from collections import deque

def solve():
    mat = [list(input()) for _ in range(n)]
    players = [deque() for _ in range(p)]
    ans = [0] * p
    rest = 0
    for i in range(n):
        for j in range(m):
            if mat[i][j].isdigit():
                pi = int(mat[i][j]) - 1
                players[pi].append(i * m + j)
                ans[pi] += 1
            elif mat[i][j] == '.':
                rest += 1
    
    dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    while rest:
        for pi in range(p):
            speed = a[pi]
            for _ in range(speed):
                q = players[pi]
                if not q: # 關鍵優化
                    break
                for _ in range(len(q)):
                    msk = q.popleft()
                    i, j = divmod(msk, m)
                    for dx, dy in dirs:
                        x, y = i + dx, j + dy
                        if not (0 <= x < n and 0 <= y < m):
                            continue
                        if mat[x][y] != '.':
                            continue
                        ans[pi] += 1
                        rest -= 1
                        if rest == 0:
                            print(*ans)
                            return
                        mat[x][y] = str(pi + 1)
                        q.append(x * m + y)
    print(*ans)
               
for _ in range(1):
    n, m, p = MII()
    a = list(MII())
    solve()