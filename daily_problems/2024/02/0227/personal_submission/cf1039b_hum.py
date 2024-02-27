import random

n, k = map(int, input().split())

l, r = 1, n


def q(l, r):
  print(l, r, flush=True)
  if input()[0] == 'Y':
    return True
  else:
    return False


while True:
  while r - l > 50:
    mid = l + r >> 1
    if q(l, mid):
      r = mid
    else:
      l = mid + 1
    l = max(1, l - k)
    r = min(n, r + k)

  x = random.randint(l, r)
  if q(x, x):
    exit()

  l = max(1, l - k)
  r = min(n, r + k)
