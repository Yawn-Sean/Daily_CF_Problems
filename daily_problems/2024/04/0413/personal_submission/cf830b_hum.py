from bisect import bisect_left


class FenwickTree:
  def __init__(self, n):
    self.N = n
    self.bit = [0] * n

  def get_sum(self, l, r):
    if l > r:
      return 0
    return self.__get_sum(r) - self.__get_sum(l - 1)

  def __get_sum(self, r):
    res = 0
    while r >= 0:
      res += self.bit[r]
      r = (r & (r + 1)) - 1
    return res

  def add(self, idx, v):
    while idx < self.N:
      self.bit[idx] += v
      idx = idx | (idx + 1)


n = int(input())
a = list(map(int, input().split()))
m = max(a)
tmp = [[] for _ in range(m + 1)]
for i, v in enumerate(a):
  tmp[v].append(i)

fenwick = FenwickTree(n)

cur = 0
res = 0
for i in range(m + 1):
  l = len(tmp[i])
  if l == 0: continue
  idx = bisect_left(tmp[i], cur)
  for j in range(l):
    p = tmp[i][(j + idx) % l]
    if p >= cur:
      res += (p - cur + 1) + fenwick.get_sum(cur, p)
    else:
      res += (n - cur + p + 1) + fenwick.get_sum(cur, n - 1) + fenwick.get_sum(0, p)
    fenwick.add(p, -1)
    cur = p

print(res)
