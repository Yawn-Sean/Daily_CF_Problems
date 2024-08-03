n, m = map(int, input().split())

cnt = [0] * m
for i in range(1, min(m + 1, n + 1)):
  c = (n - i) // m + 1
  cnt[i * i % m] += c

res = 0
for i in range(m):
  o = (m - i) % m
  res += cnt[i] * cnt[o]

print(res)
