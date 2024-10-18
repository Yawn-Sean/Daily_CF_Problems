n, nn, m = map(int, input().split())
c = [[float('inf')] * (nn + 1) for _ in range(n + 1)]
s = [0] * (n + 1)
a = [[] for _ in range(n + 1)]

for i in range(1, n + 1):
    ch = input().strip()
    for j in range(1, nn + 1):
        if ch[j - 1] == '1':
            s[i] += 1
            a[i].append(j)  # 记录第i天的课程时间段
    c[i][s[i]] = 0

    for len_ in range(1, s[i] + 1):
        for l in range(1, s[i] - len_ + 2):
            r = l + len_ - 1
            c[i][s[i] - len_] = min(c[i][s[i] - len_], a[i][r - 1] - a[i][l - 1] + 1)

f = [[float('inf')] * (m + 1) for _ in range(n + 1)]
for j in range(m + 1):
    f[0][j] = 0

for i in range(1, n + 1):
    for j in range(m + 1):
        for k in range(min(j, s[i]) + 1):
            f[i][j] = min(f[i][j], f[i - 1][j - k] + c[i][k])

print(f[n][m])
