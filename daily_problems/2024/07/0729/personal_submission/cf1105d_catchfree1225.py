import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from collections import deque

def solve():
    mat = [list(input()) for _ in range(n)]
    players = [deque() for _ in range(p)]
    ans = [0] * p
    for i in range(n):
        for j in range(m):
            if mat[i][j].isdigit():
                pi = int(mat[i][j]) - 1
                players[pi].append(i * m + j)
                ans[pi] += 1
    
    notes = [str(i) for i in range(1, p + 1)]
    dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    while True: # 有可能跑不完，不可用rest
        flg = False
        for pi in range(p):
            speed = a[pi]
            for _ in range(speed):
                q = players[pi]
                if not q: # 關鍵優化1
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
                        mat[x][y] = notes[pi]
                        q.append(x * m + y)
            else:
                flg = True # 還能跑, 關鍵優化2
        if not flg: break
    print(*ans)
               
for _ in range(1):
    n, m, p = MII()
    a = list(MII())
    solve()
