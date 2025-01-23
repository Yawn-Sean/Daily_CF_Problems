n, m = MII()

a = []
for _ in range(n):
    a.append(II())

b = []
for _ in range(m):
    l, r, _ = MII()
    if l == 1:
        b.append(r)

a.sort()
a.append(10 ** 9)
b.sort()
m = len(b)
ans = inf
j = 0
for i, x in enumerate(a):
    while j < m and b[j] < x:
        j += 1
    ans = fmin(ans, m - j + i)

print(ans)
