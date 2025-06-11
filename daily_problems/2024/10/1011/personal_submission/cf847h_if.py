n = int(input())
a = list(map(int, input().split()))
c = a[:]
b = [0] * n
for i in range(1, n):
    b[i] = max(0, c[i - 1] + 1 - a[i])
    c[i] += b[i]
bb = b[:]
for i in range(1, n):
    b[i] += b[i - 1]
c = a[:]
d = [0] * n
for i in range(n - 2, -1, -1):
    d[i] = max(0, c[i + 1] + 1 - c[i])
    c[i] += d[i]
dd = d[:]
for i in range(n - 2, -1, -1):
    d[i] += d[i + 1]
ans = float('inf')
for i in range(n):
    ans = min(ans, d[i] + b[i] - min(bb[i], dd[i]))
print(ans)
