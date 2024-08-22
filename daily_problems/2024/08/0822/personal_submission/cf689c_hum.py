n = int(input())
l = 1
r = 10 ** 18


def check(x):
  res = 0
  for i in range(2, x):
    t = i ** 3
    if t > x:
      break
    res += x // t
  return res


while l < r:
  mid = l + r >> 1
  if check(mid) >= n:
    r = mid
  else:
    l = mid + 1

if check(l) != n:
  print(-1)
else:
  print(l)
