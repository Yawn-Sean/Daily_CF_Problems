n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
x, y = 0, 0
for i in a:
  x ^= i
for i in b:
  y ^= i

if x ^ y != 0:
  print("NO")
  exit()

res = [[0] * m for _ in range(n)]

for i in range(n):
  res[i][0] = a[i]

for i in range(m):
  res[0][i] = b[i]

res[0][0] = b[0] ^ x ^ a[0]
print("YES")
for i in range(n):
  print(*res[i], sep=' ')
