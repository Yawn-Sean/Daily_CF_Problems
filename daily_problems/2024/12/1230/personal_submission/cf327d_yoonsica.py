'''
先建蓝，然后从一个蓝bfs，除了初始点外，其他可以拆了建红
https://codeforces.com/contest/327/submission/299025087
'''
n, m = RII()
g = [[0] * m for _ in range(n)]
ans = []
for i in range(n):
    for j, x in enumerate(RS()):
        if x == '.':
            ans.append(f'B {i + 1} {j + 1}')
            g[i][j] = 1

for i, row in enumerate(g):
    for j, x in enumerate(row):
        if x:
            cur = [(i, j)]
            g[i][j] = 0
            ops = []
            while cur:
                nxt = []
                for u, v in cur:
                    for nx, ny in (u + 1, v), (u - 1, v), (u, v + 1), (u, v - 1):
                        if 0 <= nx < n and 0 <= ny < m and g[nx][ny]:
                            nxt.append((nx, ny))
                            g[nx][ny] = 0
                            ops.append(f'R {nx + 1} {ny + 1}')
                            ops.append(f'D {nx + 1} {ny + 1}')
                cur = nxt
            ans += ops[::-1]
print(len(ans))
print('\n'.join(ans))