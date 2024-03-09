n = int(input())
l = []
for _ in range(n):
  a, b = map(int, input().split())
  l.append((a, b))


def h(v):
  res = []
  i = 2
  while i * i <= v:
    if v % i == 0:
      res.append(i)
      while v % i == 0:
        v //= i
    i += 1
  if v > 1:
    res.append(v)
  return res


g = set()
for i in h(l[0][0]):
  g.add(i)
for i in h(l[0][1]):
  g.add(i)


def check(arr, x):
  for a, b in arr:
    if a % x != 0 and b % x != 0:
      return False
  return True


for i in g:
  if check(l[1:], i):
    print(i)
    break
else:
  print(-1)
