mod = 10 ** 9 + 7


class FenwickTree:
  def __init__(self, n):
    self.N = n
    self.bit = [0] * n

  def get_sum(self, l, r):
    if l > r:
      return 0
    return (self.__get_sum(r) - self.__get_sum(l - 1)) % mod

  def __get_sum(self, r):
    res = 0
    while r >= 0:
      res += self.bit[r]
      if res >= mod:
        res -= mod
      r = (r & (r + 1)) - 1
    return res

  def add(self, idx, v):
    while idx < self.N:
      self.bit[idx] += v
      if self.bit[idx] >= mod:
        self.bit[idx] -= mod
      idx = idx | (idx + 1)

  def get(self, idx):
    return self.get_sum(idx, idx)

  def set(self, idx, v):
    self.add(idx, (v - self.get(idx)) % mod)


n = int(input())
a = list(map(int, input().split()))

m = max(a)

fen = FenwickTree(m + 1)

for x in a:
  t = (x + fen.get_sum(0, x) * x) % mod
  fen.set(x, t)

print(fen.get_sum(0, m))
