n, m, k = map(int, input().split())


def f(x):
  return x * (m // max(1, k - n // x + 2))


res = 0
for i in range(1, min(n + 1, 40000)):
  res = max(res, f(i))
  res = max(res, f(n // i))

print(res if res else -1)
