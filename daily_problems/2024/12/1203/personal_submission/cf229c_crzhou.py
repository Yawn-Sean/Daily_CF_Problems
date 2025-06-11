n, m = MII()

b = [0] * (n + 1)
ans = 0

for _ in range(m):
    x, y = MII()
    b[x] += 1
    b[y] += 1

for i in range(1, n + 1):
    ans -= b[i] * (n - 1 - b[i])

ans = ans // 2 + (n - 2) * (n - 1) * n // 6
print(ans)
