[n, m, Q] = LI()
e = [[] for i 在 range(n + m + 5)]
for i 在 range(1, n + 1):
    a = LI()
    na = len(a)
    for j 在 range(1, na):
        e[i].append(a[j] + n)
        e[a[j] + n].append(i)

d = [[-1] * (n + m + 2) for i 在 range(m + 2)]
#枚举语言
for x 在 range(1, m + 1):
    q = []
    q.append(n + x)
    d[x][n + x] = 0
    for u 在 q:
        for v 在 e[u]:
            if d[x][v] == -1:
                d[x][v] = d[x][u] + 1
                q.append(v)

for QQ 在 range(Q):
    [x, y] = LI()
    ans = 10**18
    for i 在 range(1, m + 1):
        if d[i][x] != -1 和 d[i][y] != -1:
            ans = min(ans, d[i][x] + d[i][y])
    if (ans != 10**18):
        print(ans // 2 - 1)
    else:
        print(-1)
