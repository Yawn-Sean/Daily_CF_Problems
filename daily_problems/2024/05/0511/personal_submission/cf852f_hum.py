class Factorial:
  def __init__(self, n, mod) -> None:
    n += 1
    self.mod = mod
    self.f = [1 for _ in range(n)]
    self.g = [1 for _ in range(n)]

    for i in range(1, n):
      self.f[i] = self.f[i - 1] * i % self.mod

    self.g[-1] = pow(self.f[-1], mod - 2, mod)
    #self.g[-1] = pow(self.f[-1], -1, mod)

    for i in range(n - 2, -1, -1):
      self.g[i] = self.g[i + 1] * (i + 1) % self.mod

  def comb(self, n, m):
    if n < m or m < 0 or n < 0: return 0
    return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod


n, m, a, q = map(int, input().split())

powers = [1]
for i in range(10 ** 6 + 123):
  powers.append(powers[-1] * a % q)
  if powers[-1] == 1:
    powers.pop()
    break

phi = len(powers)
fact = Factorial(m, phi)

res = [1] * n
for i in range(n - 2, -1, -1):
  res[i] = (res[i + 1] + fact.comb(m, n - 1 - i)) % phi

print(*(powers[x] for x in res))
