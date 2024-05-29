a, b, c = map(int, input().split())
mod = 998244353


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

  def fac(self, n):
    return self.f[n]

  def comb(self, n, m):
    if n < m or m < 0 or n < 0: return 0
    return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod


m = max(a, b, c)
fac = Factorial(m, mod)


def f(a, b):
  res = 0
  for i in range(0, min(a, b) + 1):
    res += fac.comb(a, i) * fac.comb(b, i) * fac.fac(i)
    res %= mod
  return res


x = f(a, b)
y = f(b, c)
z = f(a, c)

res = x * y * z % mod
print(res)
