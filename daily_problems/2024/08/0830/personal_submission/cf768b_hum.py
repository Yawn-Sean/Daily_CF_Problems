n, l, r = map(int, input().split())


def f(x, k):
  if x == 0:
    return 0
  l = x.bit_length() - 1
  length = 1 << l
  if k > length:
    return f(x >> 1, k - length)
  elif k < length:
    return f(x >> 1, k)
  return x % 2


res = 0
for i in range(l, r + 1):
  res += f(n, i)

print(res)
