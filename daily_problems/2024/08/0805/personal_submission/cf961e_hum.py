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


import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))
b = [0] * n
d = [[] for _ in range(n)]
for i in range(1, n):
  d[min(i - 1, a[i])].append(i)

fen = FenwickTree(n)

res = 0
for i in range(n):
  fen.add(min(a[i], n - 1), 1)
  for j in d[i]:
    res += fen.get_sum(j, n - 1)

print(res)
