k = int(input())
l = 1
r = 10 ** 12


def cal(x):
  low = 1
  high = 9
  res = 0
  while low <= x:
    res += (min(x, high) - low + 1) * len(str(low))
    low = low * 10
    high = high * 10 + 9
  return res


while l < r:
  mid = l + r >> 1
  if cal(mid) >= k:
    r = mid
  else:
    l = mid + 1

x = k - cal(l - 1)

print(str(l)[x - 1])
