n, m = map(int, input().split())
xs = [0] * n
ys = [0] * n

for i in range(n):
  xs[i], ys[i] = map(int, input().split())

res = [0] * n

idx = sorted(range(n), key=lambda x: xs[x] - ys[x])
acc_x = 0
acc_y = sum(ys)

for i in range(n):
  p = idx[i]
  acc_y -= ys[p]
  res[p] = acc_x + i * ys[p] + acc_y + (n - i - 1) * xs[p]
  acc_x += xs[p]

for _ in range(m):
  u, v = map(lambda x: int(x) - 1, input().split())
  val = min(xs[u] + ys[v], xs[v] + ys[u])
  res[u] -= val
  res[v] -= val

print(*res)
