n = int(input())


def query(x):
  print('?', x, flush=True)
  a = int(input())
  print('?', x + n // 2, flush=True)
  b = int(input())
  return a - b


if n % 4 != 0:
  print('!', -1)
  exit()

t = query(1)
if t == 0:
  print('!', 1)
  exit()

l = 1
r = n // 2
while l < r:
  mid = (l + r + 1) // 2
  x = query(mid)
  if x * t >= 0:
    l = mid
  else:
    r = mid - 1

print('!', l)
