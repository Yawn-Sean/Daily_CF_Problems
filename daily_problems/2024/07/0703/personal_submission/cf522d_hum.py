from math import inf

n, m = map(int, input().split())
a = list(map(int, input().split()))
q = [[] for i in range(n)]

for i in range(m):
  l, r = map(lambda x: int(x) - 1, input().split())
  q[r].append((l, i))


class SegmentTree:
  def __init__(self, n, op):
    self.N = n
    self.INF = float('inf')
    self.SIZE = 1 << (n - 1).bit_length()
    self.data = [inf] * (2 * self.SIZE)
    self.OP = op

  def __push_up(self, k):
    self.data[k] = self.OP(self.data[2 * k], self.data[2 * k + 1])

  def build(self, arr):
    for i in range(self.N):
      self.data[self.SIZE + i] = arr[i]
    for i in range(self.SIZE - 1, 0, -1):
      self.__push_up(i)

  def modify(self, p, x):
    p += self.SIZE
    self.data[p] = x
    p >>= 1
    while p >= 1:
      self.__push_up(p)
      p >>= 1

  def query(self, l, r):
    # [l,r)
    if l >= r:
      return self.INF
    sml = smr = self.INF
    l += self.SIZE
    r += self.SIZE
    while l < r:
      if l & 1:
        sml = self.OP(sml, self.data[l])
        l += 1
      if r & 1:
        r -= 1
        smr = self.OP(self.data[r], smr)
      l >>= 1
      r >>= 1
    return self.OP(sml, smr)


d = dict()
seg = SegmentTree(n, min)
res = [-1] * m
for i in range(n):
  if a[i] in d:
    l = d[a[i]]
    seg.modify(l, i - l)
  for l, idx in q[i]:
    res[idx] = seg.query(l, i + 1)
  d[a[i]] = i

for r in res:
  if r == inf:
    print(-1)
  else:
    print(r)
