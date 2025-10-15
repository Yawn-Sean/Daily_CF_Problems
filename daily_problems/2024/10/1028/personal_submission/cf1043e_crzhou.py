data = input().split()
idx = 0
n = int(data[idx])
m = int(data[idx + 1])
idx += 2

a = [0] * (n + 1)
b = [0] * (n + 1)
c = []
for i in range(1, n + 1):
    a[i] = int(data[idx])
    b[i] = int(data[idx + 1])
    c.append((a[i] - b[i], i))
    idx += 2

c.sort()
id = [0] * (n + 1)

for i in range(1, n + 1):
    id[c[i - 1][1]] = i

sum_f = [0] * (n + 2)
sum_s = [0] * (n + 2)

for i in range(1, n + 1):
    sum_f[i] = sum_f[i - 1] + a[c[i - 1][1]]

for i in range(n, 0, -1):
    sum_s[i] = sum_s[i + 1] + b[c[i - 1][1]]

ans = [0] * (n + 1)

for i in range(1, n + 1):
    ans[i] = a[i] * (n - id[i]) + b[i] * (id[i] - 1) + sum_f[id[i] - 1] + sum_s[id[i] + 1]

for _ in range(m):
    x = int(data[idx])
    y = int(data[idx + 1])
    idx += 2
    if id[x] < id[y]:
        ans[x] -= a[x] + b[y]
        ans[y] -= a[x] + b[y]
    else:
        ans[x] -= a[y] + b[x]
        ans[y] -= a[y] + b[x]

print(" ".join(map(str, ans[1:])))
