from collections import defaultdict


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

  def comb(self, n, m):
    if n < m or m < 0 or n < 0: return 0
    return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod


import sys

input = lambda: sys.stdin.readline().rstrip()

n, k = map(int, input().split())
mod = 10 ** 9 + 7
fact = Factorial(n, mod)

diff = defaultdict(int)

for _ in range(n):
  l, r = map(int, input().split())
  diff[l] += 1
  diff[r + 1] -= 1

keys = sorted(diff.keys())

cur = 0
res = 0

for i in range(len(keys) - 1):
  cur += diff[keys[i]]
  res = (res + fact.comb(cur, k) * (keys[i + 1] - keys[i])) % mod

print(res)
