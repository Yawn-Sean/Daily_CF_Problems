a, b = map(int, input().split())

s = 0
x = 1
while s + x <= a + b:
  s += x
  x += 1

x -= 1
res1, res2, = [], []

for i in range(x, 0, -1):
  if a >= i:
    res1.append(i)
    a -= i
  else:
    res2.append(i)

print(len(res1))
print(*res1)
print(len(res2))
print(*res2)
