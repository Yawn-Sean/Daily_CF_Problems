class SegmentTree:
  def __init__(self, n, op):
    self.N = n
    self.INF = -float('inf')
    self.SIZE = 1 << (n - 1).bit_length()
    self.data = [0] * (2 * self.SIZE)
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


n = int(input())
a = list(map(int, input().split()))

dp = [0] * n
seg = SegmentTree(n, max)

idx = sorted(range(n), key=lambda x: a[x], reverse=True)

for ii in range(n):
  i = idx[ii]
  dp[i] = seg.query(0, i + 1) + 1
  seg.modify(i, dp[i])

res = dict()
for i in range(n):
  res.setdefault(dp[i], []).append(a[i])

for i in sorted(res):
  print(*res[i])
