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


import sys

input = lambda: sys.stdin.readline().rstrip()
n, k = map(int, input().split())
k += 1
fen = [FenwickTree(n + 1) for _ in range(k + 1)]
fen[0].add(0, 1)
for _ in range(n):
  a = int(input())
  for i in range(1, k + 1):
    fen[i].add(a, fen[i - 1].get_sum(0, a - 1))

print(fen[k].get_sum(0, n))
