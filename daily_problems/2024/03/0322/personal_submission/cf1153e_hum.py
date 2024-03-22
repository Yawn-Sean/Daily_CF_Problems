def query(x1, y1, x2, y2):
  print('?', x1, y1, x2, y2, flush=True)
  return int(input())


def answer(x1, y1, x2, y2):
  print('!', x1, y1, x2, y2)


n = int(input())

odd = []
res = []

for i in range(1, n):
  tmp = query(i, 1, i, n)
  if tmp & 1:
    odd.append(i)

if len(odd) & 1:
  odd.append(n)

if len(odd) == 2:
  for x in odd:
    l, r = 1, n
    while l < r:
      mid = l + r >> 1
      tmp = query(x, l, x, mid)
      if tmp & 1:
        r = mid
      else:
        l = mid + 1

    res.append(x)
    res.append(l)

  answer(res[0], res[1], res[2], res[3])

else:
  for i in range(1, n):
    tmp = query(1, i, n, i)
    if tmp & 1:
      odd.append(i)

  if len(odd) & 1:
    odd.append(n)

  for y in odd:
    l, r = 1, n
    while l < r:
      mid = l + r >> 1
      tmp = query(l, y, mid, y)
      if tmp & 1:
        r = mid
      else:
        l = mid + 1
    res.append(l)
    res.append(y)

  answer(res[0], res[1], res[2], res[3])
