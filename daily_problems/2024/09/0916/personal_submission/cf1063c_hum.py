n = int(input())


def q(x, y):
  print(x, y, flush=True)
  return input()[0]


n -= 1

n1 = n // 2
n2 = n - n1

l, r = 0, 10 ** 9
x = q(0, 0)
for _ in range(n1):
  mid = (l + r) // 2
  t = q(mid, 0)
  if t == x:
    l = mid + 1
  else:
    r = mid - 1

t1 = l + r >> 1

l, r = 0, 10 ** 9
for _ in range(n2):
  mid = (l + r) // 2
  t = q(0, mid)
  if t == x:
    l = mid + 1
  else:
    r = mid - 1

t2 = l + r >> 1

print(0, t2, t1, 0, flush=True)
