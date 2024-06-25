s = input()
n = len(s)
c = [[0 for j in range(n + 2)] for i in range(2)]

for i in range(n) :
    x, y = i, i
    c[0][i] = 1
    while True :
        x, y = x - 1, y + 1
        if x < 0 or y >= n or s[x] != s[y] :
            break
        c[0][i] += 1

for i in range(n - 1) :
    x, y = i, i + 1
    c[1][i] = 0
    while True :
        if s[x] != s[y] :
            break
        c[1][i] += 1
        x, y = x - 1, y + 1
        if x < 0 or y >= n :
            break

ans = [0] * (n + 2)
ans[1] = n

for i in range(n) :
    f = [0] * (n + 2)
    f[i] = 1
    for j in range(i + 1, n) :
        l = j - i + 1
        o = i + j
        h = o >> 1
        if c[o & 1][h] < h - i + 1 :
            continue

        f[j] = f[i + l // 2 - 1] + 1
        ans[f[j]] += 1

for i in range(n - 1, 0, -1) :
    ans[i] += ans[i + 1]
print(*ans[1 : n + 1])
