import sys
input = lambda: sys.stdin.readline().rstrip()
n, s = map(int, input().split())
res = 0
t1 = []
t2 = []
acc1, acc2 = 0, 0
for _ in range(n):
  c, a, b = map(int, input().split())
  if a > b:
    t1.append((a - b, c))
    res += c * a
    acc1 += c
  else:
    t2.append((b - a, c))
    res += c * b
    acc2 += c

acc1 %= s
acc2 %= s
if acc1 + acc2 > s:
  print(res)
  exit()

t1.sort()
t2.sort()
m1, m2 = 0, 0

for v, c in t1:
  m1 += min(c, acc1) * v
  acc1 -= min(c, acc1)
  if acc1 == 0:
    break

for v, c in t2:
  m2 += min(c, acc2) * v
  acc2 -= min(c, acc2)
  if acc2 == 0:
    break

print(res - min(m1, m2))
