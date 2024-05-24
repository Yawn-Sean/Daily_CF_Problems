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
b = list(map(int, input().split()))
order1 = [0] * n
fen = FenwickTree(n)
for i in range(n):
  order1[i] = a[i] - fen.get_sum(0, a[i])
  fen.add(a[i], 1)

order2 = [0] * n
fen = FenwickTree(n)
for i in range(n):
  order2[i] = b[i] - fen.get_sum(0, b[i])
  fen.add(b[i], 1)

order = [0] * n
carry = 0
for i in range(n - 1, -1, -1):
  carry, order[i] = divmod(order1[i] + order2[i] + carry, n - i)

res = [0] * n
fen = FenwickTree(n)
fen.set_bit([1] * n)

for i in range(n):
  l, r = 0, n - 1
  while l < r:
    m = (l + r) // 2
    if fen.get_sum(0, m) >= order[i] + 1:
      r = m
    else:
      l = m + 1
  res[i] = l
  fen.add(res[i], -1)

print(*res)
