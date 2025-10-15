n, p = MII()
ls = [0] * n
rs = [0] * n
cnt = [0] * n

for i in range(n):
    ls[i], rs[i] = MII()
    cnt[i] = rs[i] // p - (ls[i] + p - 1) // p + 1

ans = 0
for i in range(n):
    a = rs[i] - ls[i] + 1
    b = rs[i - 1] - ls[i - 1] + 1
    ans += (a * cnt[i - 1] + (b - cnt[i - 1]) * (cnt[i])) / (a * b)

print(ans * 2000)
