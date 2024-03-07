m, n = map(int, input().split())

res = 0
for i in range(1, m + 1):
  res += i * (pow(i / m, n) - pow(((i - 1) / m), n))

print(res)
