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
xs, ys = [], []
for _ in range(n):
  x, y = map(int, input().split())
  xs.append(x)
  ys.append(y)

tmp_xs = sorted(set(xs))
d_x = {x: i for i, x in enumerate(tmp_xs)}
d_y = {y: [] for y in set(ys)}

for i in range(n):
  d_y[ys[i]].append(d_x[xs[i]])

f = FenwickTree(n)

res = 0
for y in sorted(d_y, reverse=True):
  d_y[y].sort()
  for x in d_y[y]:
    f.set(x, 1)
  d_y[y].append(n)
  for i in range(len(d_y[y]) - 1):
    res += f.get_sum(0, d_y[y][i]) * f.get_sum(d_y[y][i], d_y[y][i + 1] - 1)
print(res)
