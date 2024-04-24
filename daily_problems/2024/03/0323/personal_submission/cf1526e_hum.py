import sys

input = lambda: sys.stdin.readline().rstrip()


class Factorial:
  def __init__(self, n, mod) -> None:
    n += 5
    self.mod = mod
    self.f = [1 for _ in range(n)]
    self.g = [1 for _ in range(n)]

    for i in range(1, n):
      self.f[i] = self.f[i - 1] * i % self.mod

    # self.g[-1] = pow(self.f[-1], mod - 2, mod)
    self.g[-1] = pow(self.f[-1], -1, mod)

    for i in range(n - 2, -1, -1):
      self.g[i] = self.g[i + 1] * (i + 1) % self.mod

  def fac(self, n):
    return self.f[n]

  def fac_inv(self, n):
    return self.g[n]

  def comb(self, n, m):
    if n < m or m < 0 or n < 0: return 0
    return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod

  def perm(self, n, m):
    if n < m or m < 0 or n < 0: return 0
    return self.f[n] * self.g[n - m] % self.mod

  def catalan(self, n):
    return (self.comb(2 * n, n) - self.comb(2 * n, n - 1)) % self.mod

  def inv(self, n):
    return self.f[n - 1] * self.g[n] % self.mod


n, k = map(int, input().split())
s = list(map(int, input().split()))

rk = [-1] * (n + 1)

for i in range(n):
  rk[s[i]] = i

mod = 998244353
fact = Factorial(k + n, mod)

cnt = 0
for i in range(n - 1):
  x, y = s[i], s[i + 1]
  if rk[x + 1] < rk[y + 1]:
    cnt += 1

print(fact.comb(k + cnt, n))
