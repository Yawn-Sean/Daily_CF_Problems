n, l = map(int, input().split())
c = list(map(int, input().split()))

while len(c) < 32:
  c.append(float('inf'))

for i in range(32):
  cur = c[i]
  for j in range(i, 32):
    c[j] = min(c[j], cur)
    cur *= 2

for i in range(30, -1, -1):
  c[i] = min(c[i], c[i + 1])

res = float('inf')
s = 0
for i in range(30, -1, -1):
  res = min(res, s + c[i + 1])
  if l >> i & 1 == 1:
    s += c[i]

res = min(res, s)

print(res)
