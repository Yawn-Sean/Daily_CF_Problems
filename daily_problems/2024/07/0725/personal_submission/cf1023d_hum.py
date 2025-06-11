import sys

input = lambda: sys.stdin.readline().rstrip()


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


n, q = map(int, input().split())
a = list(map(int, input().split()))

if 0 in a:
  idx = a.index(0)
  last = 1
  for i in range(n):
    if a[i] == 0:
      a[i] = last
    last = a[i]
  if q not in a:
    a[idx] = q

if q not in a:
  print("NO")
  exit()

pos = [[] for _ in range(q + 1)]
for i in range(n):
  pos[a[i]].append(i)

fen = FenwickTree(n)

for i in range(1, q + 1):
  if len(pos[i]) and fen.get_sum(pos[i][0], pos[i][-1]) >= 1:
    print("NO")
    exit()
  for p in pos[i]:
    fen.add(p, 1)

print("YES")
print(*a)
