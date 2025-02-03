def f(g, n, m):
    a = []
    b = []
    for i in range(n):
        w = sorted(enumerate(g[i]), key=lambda x: x[1])
        d = [(w[0][0], 1)]
        for j in range(m - 1):
            d.append((w[j + 1][0], d[-1][1] + (1 if w[j + 1][1] > w[j][1] else 0)))
        b.append(d[-1][1])
        x = [0]*m
        for i, j in d:
            x[i] = j
        a.append(x)
    return (a, b)


n, m = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(n)]
x1, y1 = f(g, n, m)
x2, y2 = f(list(zip(*g)), m, n)
w = [[0]*m for i in range(n)]
for i in range(n):
    for j in range(m):
        c = abs(x1[i][j]-x2[j][i])
        if x1[i][j] < x2[j][i]:
            w[i][j] = max(y2[j], y1[i]+c)
        else:
            w[i][j] = max(y2[j]+c, y1[i])
for i in w:
    print(' '.join(map(str, i)))
