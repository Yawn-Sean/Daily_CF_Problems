# https://codeforces.com/contest/1105/submission/273316097

n, m, k = RII()
dis = RILIST()
grid = []
ans = [0] * k
q = [[] for _ in range(k)]
for i in range(n):
    grid.append(list(RS()))
    for j, x in enumerate(grid[-1]):
        if x not in '.#':
            t = int(x) - 1
            q[t].append((i, j))
            ans[t] += 1

while True:
    flag = False
    for u in range(k):
        cur = q[u]
        for _ in range(dis[u]):
            nxt = []
            for x, y in cur:
                for nx, ny in (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1):
                    if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == '.':
                        grid[nx][ny] = u
                        nxt.append((nx, ny))
                        ans[u] += 1
            cur = nxt
            if not nxt:
                break
            else:
                flag = True
        q[u] = cur
    if not flag:
        break

print(' '.join(map(str, ans)))
