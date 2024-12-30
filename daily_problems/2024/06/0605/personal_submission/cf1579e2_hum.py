class FenwickTree:
  def __init__(self, n):
    self.N = n
    self.bit = [0] * n

  def set_bit(self, arr):
    self.bit = arr[:]

    for i in range(self.N):
      if i | (i + 1) < self.N:
        self.bit[i | (i + 1)] += self.bit[i]

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


t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  vals = {v: i for i, v in enumerate(sorted(set(a)))}
  m = len(vals)
  fen = FenwickTree(m)
  res = 0
  for i in range(n):
    v = vals[a[i]]
    res += min(fen.get_sum(0, v - 1), fen.get_sum(v + 1, m - 1))
    fen.add(v, 1)
  print(res)
