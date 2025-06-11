def query(r1, c1, r2, c2):
  print('?', r1, c1, r2, c2, flush=True)
  return input()


def answer(s):
  print('!', s, flush=True)


n = int(input())

x, y = 1, 1
tmp1 = []

for _ in range(n - 1):
  if query(x, y + 1, n, n) == "YES":
    y += 1
    tmp1.append('R')
  else:
    x += 1
    tmp1.append('D')

x, y = n, n
tmp2 = []

for _ in range(n - 1):
  if query(1, 1, x - 1, y) == "YES":
    x -= 1
    tmp2.append('D')
  else:
    y -= 1
    tmp2.append('R')

answer(''.join(tmp1) + ''.join(reversed(tmp2)))
