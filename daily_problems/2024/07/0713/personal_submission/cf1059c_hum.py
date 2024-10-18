n = int(input())

x = 1
res = []
while n > 3:
  cnt = (n + 1) // 2
  res.extend([x] * cnt)
  x *= 2
  n //= 2

if n == 3:
  res.extend([x, x, x * 3])
elif n == 2:
  res.extend([x, x * 2])
elif n == 1:
  res.append(x)
print(*res)
