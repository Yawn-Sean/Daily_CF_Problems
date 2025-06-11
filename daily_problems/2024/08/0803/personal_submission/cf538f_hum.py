class FenwickTree:
  def __init__(self, n):
    self.N = n
    self.bit = [0] * n

  def get_sum(self, l, r):
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
a = list(map(lambda x: int(x) - 1, input().split()))

fen = FenwickTree(n)

res = [0] * (n - 1)

for i in sorted(range(n), key=lambda x: a[x]):
  for k in range(1, n):
    l, r = k * i + 1, k * i + k
    if l >= n:
      break
    r = min(r, n - 1)
    res[k - 1] += fen.get_sum(l, r)
  fen.add(i, 1)

print(*res)
