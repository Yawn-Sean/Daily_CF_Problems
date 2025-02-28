n, m = map(int, input().split())
a, b1, b2, c = 0, 0, 0, 0

for i in range(n):
  nums = list(map(int, input().split()))
  x = 4 * i + 2
  for j in range(m):
    a += nums[j]
    y = 4 * j + 2
    b1 += 2 * nums[j] * x
    b2 += 2 * nums[j] * y
    c += nums[j] * (x * x + y * y)


def search(a, b):
  if a == 0: return 0
  x = b // (a * 8)
  return x if abs(x * a * 8 - b) <= abs((x + 1) * a * 8 - b) else x + 1


x = search(a, b1) * 4
y = search(a, b2) * 4

print(a * (x * x + y * y) - b1 * x - b2 * y + c)
print(x // 4, y // 4)
