n, k = MII()
cars = LII()
favs = LII()
haps = [0] + LII()

y = k * n
f = [[0] * (y + 1) for _ in range(n + 1)]
f[1][1] = haps[1]
for i in range(n):
    for j in range(y):
        for t in range(j + 1, -1, -1):
            if j + 1 - t <= k:
                tmp = j + 1 - t
            else:
                break
            f[i + 1][j + 1] = fmax(f[i + 1][j + 1], f[i][t] + haps[tmp])

cnt = Counter(cars)
cntp = Counter(favs)
ans = 0

for k, v in cntp.items():
    j = cnt[k]
    ans += f[v][j]

print(ans)
