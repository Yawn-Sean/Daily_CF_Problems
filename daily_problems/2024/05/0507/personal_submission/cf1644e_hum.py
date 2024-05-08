import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n = int(input())
  s = input()

  k = len(s)

  pos = -1
  for i in range(k):
    if s[i] != s[0]:
      pos = i
      break

  if pos == -1:
    print(n)
    continue

  res = pos + (n - pos) * n

  dx, dy = 0, 0
  for i in range(pos, k):
    if s[i] == 'R':
      dy += 1
    else:
      dx += 1

  res -= dx * dy
  print(res)
