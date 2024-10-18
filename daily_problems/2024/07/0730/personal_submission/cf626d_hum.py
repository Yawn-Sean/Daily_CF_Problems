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
a = list(map(int, input().split()))
a.sort()
m = a[-1]
fen = FenwickTree(m)
diff = [0] * m
for i in range(n):
  for j in range(i):
    diff[a[i] - a[j]] += 1

for i in range(m):
  fen.add(i, diff[i])

res = 0
for i in range(m):
  for j in range(m):
    cur = diff[i] * diff[j]
    need = i + j + 1
    if need < m:
      res += cur * fen.get_sum(need, m - 1)

print(res / ((n - 1) * n // 2) ** 3)
