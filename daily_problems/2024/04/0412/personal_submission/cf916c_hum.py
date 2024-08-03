n, m = map(int, input().split())
p = 100003
print(p, p)
for i in range(1, n - 1):
  print(i, i + 1, 1)
print(n - 1, n, p - (n - 2))

m -= n - 1

for i in range(1, n + 1):
  for j in range(i + 2, n + 1):
    if m == 0:
      exit()
    print(i, j, 10 ** 9)
    m -= 1
