n, x = map(int, input().split())
if n == 2 and x == 0:
  print("NO")
  exit()

print("YES")
if n == 1:
  print(x)
  exit()

if n == 2:
  print(0, x)
  exit()

s = 0
res = []
for i in range(1, n - 2):
  s ^= i
  res.append(i)

if s == x:
  a, b = 1 << 17, 1 << 18
  res.extend([a, b, a ^ b])
  print(*res)
else:
  a = 1 << 17
  res.extend([0, a, a ^ s ^ x])
  print(*res)
