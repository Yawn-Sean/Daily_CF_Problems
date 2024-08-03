import sys

input = lambda: sys.stdin.readline().rstrip()


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

  def get(self, idx):
    return self.get_sum(idx, idx)

  def set(self, idx, v):
    self.add(idx, v - self.get(idx))


n = int(input())

d = dict()

for _ in range(n):
  a, b = map(int, input().split())
  if a not in d:
    d[a] = a
  if b not in d:
    d[b] = b
  d[a], d[b] = d[b], d[a]

pos = {d[v]: v for v in d}
pts = sorted(d)
map_pos = {v: i * 2 for i, v in enumerate(pts)}

n = len(pts)
fen = FenwickTree(2 * n - 1)

res = 0
for i in range(n - 1, -1, -1):
  if i < n - 1:
    p = 2 * i + 1
    res += fen.get_sum(0, p) * (pts[i + 1] - pts[i] - 1)
    fen.add(p, pts[i + 1] - pts[i] - 1)

  p = map_pos[pos[pts[i]]]
  res += fen.get_sum(0, p)
  fen.add(p, 1)

print(res)
