k, a, b = list(map(lambda x: int(x) - 1, input().split()))
k += 1
t1 = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(3)]
t2 = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(3)]


def f(x, y):
  if x == y:
    return 0, 0
  if x - y == 1 or x - y == -2:
    return 1, 0
  return 0, 1


def f2(arr):
  res1 = res2 = 0
  for x, y in arr:
    tmp1, tmp2 = f(x, y)
    res1 += tmp1
    res2 += tmp2
  return res1, res2


res1 = res2 = 0
res = []

if k < 20:
  for _ in range(k):
    res.append((a, b))
    a, b = t1[a][b], t2[a][b]
  print(*f2(res))
  exit()

for i in range(k):
  res.append((a, b))
  a, b = t1[a][b], t2[a][b]
  if (a, b) in res:
    j = res.index((a, b))
    l = i + 1 - j
    k -= j
    x, y = divmod(k, l)

    tmp1, tmp2 = f2(res[:j])
    res1 += tmp1
    res2 += tmp2
    tmp1, tmp2 = f2(res[j:])
    res1 += tmp1 * x
    res2 += tmp2 * x
    tmp1, tmp2 = f2(res[j:j + y])
    res1 += tmp1
    res2 += tmp2
    break

print(res1, res2)
