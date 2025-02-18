class Factorial:
  def __init__(self, n, mod) -> None:
    n += 1
    self.mod = mod
    self.f = [1 for _ in range(n)]
    self.g = [1 for _ in range(n)]

    for i in range(1, n):
      self.f[i] = self.f[i - 1] * i % self.mod

    # self.g[-1] = pow(self.f[-1], mod - 2, mod)
    self.g[-1] = pow(self.f[-1], -1, mod)

    for i in range(n - 2, -1, -1):
      self.g[i] = self.g[i + 1] * (i + 1) % self.mod

  def inv(self, n):
    return self.f[n - 1] * self.g[n] % self.mod


import sys
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = []
d = defaultdict(int)
for i in range(n):
  a.append(list(map(int, input().split())))
  s = set(a[i][1:])
  for v in s:
    d[v] += 1

mod = 998244353
fac = Factorial(10 ** 6 + 1, mod)

res = 0
for i in range(n):
  for v in a[i][1:]:
    res = (res + fac.inv(n) * fac.inv(a[i][0]) * d[v] * fac.inv(n)) % mod

print(res)
