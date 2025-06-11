k = int(input())
if k % 2 == 0:
  print("NO")
  exit()

print("YES")
n = 4 * k - 2
m = n * k // 2

print(n, m)

print(1, n // 2 + 1)

for i in range(2, k + 1):
  print(1, i)
  print(1 + n // 2, i + n // 2)

for i in range(2, k + 1):
  for j in range(k + 1, 2 * k):
    print(i, j)
    print(i + n // 2, j + n // 2)

for j in range(k + 1, 2 * k, 2):
  print(j, j + 1)
  print(j + n // 2, j + 1 + n // 2)
