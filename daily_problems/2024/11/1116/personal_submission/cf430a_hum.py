n, m = map(int, input().split())
a = list(map(int, input().split()))
for _ in range(m):
  l, r = map(int, input().split())

t = [1, 0] * (n // 2)
if len(t) < n:
  t.append(1)

res = [0] * n

j = 0
for i in sorted(range(n), key=lambda i: a[i]):
  res[i] = t[j]
  j += 1

print(*res)
