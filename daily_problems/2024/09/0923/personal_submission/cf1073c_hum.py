n = int(input())
s = input()
x, y = map(int, input().split())

acc = [[0] * 2 for _ in range(n + 1)]
for i in range(n):
  for j in range(2):
    acc[i + 1][j] = acc[i][j]
  if s[i] == 'L':
    acc[i + 1][0] -= 1
  elif s[i] == 'R':
    acc[i + 1][0] += 1
  elif s[i] == 'U':
    acc[i + 1][1] += 1
  else:
    acc[i + 1][1] -= 1

if acc[n][0] == x and acc[n][1] == y:
  print(0)
  exit()


def check(m):
  for left in range(n):
    right = left + m - 1
    if right >= n:
      break
    u, v = acc[left][0] + acc[n][0] - acc[right + 1][0], acc[left][1] + acc[n][1] - acc[right + 1][1]
    need = abs(x - u) + abs(y - v)
    if m - need >= 0 and (m - need) % 2 == 0:
      return True
  return False


l, r = 1, n
while l < r:
  m = (l + r) // 2
  if check(m):
    r = m
  else:
    l = m + 1

if check(l):
  print(l)
else:
  print(-1)
