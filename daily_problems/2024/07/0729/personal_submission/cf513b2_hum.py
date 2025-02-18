n, m = map(int, input().split())
m -= 1
res1, res2 = [], []
for i in range(n - 1):
  if m >> (n - 2 - i) & 1 == 1:
    res2.append(i + 1)
  else:
    res1.append(i + 1)

res = res1 + [n] + list(reversed(res2))
print(*res)
