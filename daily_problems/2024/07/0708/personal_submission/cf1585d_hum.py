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

t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  if len(set(a)) != n:
    print("YES")
    continue
  m = max(a) + 1
  fen = FenwickTree(m)
  res = 0
  for x in reversed(a):
    res += fen.get_sum(0, x - 1)
    fen.add(x, 1)
  if res % 2 == 0:
    print("YES")
  else:
    print("NO")
