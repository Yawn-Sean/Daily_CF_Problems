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


s1 = input()
s2 = input()
s1 = [ord(c) - ord('a') for c in s1]
s2 = [ord(c) - ord('a') for c in s2]
n = len(s1)

cnt = [0] * 26
for c in s1:
  cnt[c] += 1

mod = 10 ** 9 + 7
fact = Factorial(n, mod)


def f(s):
  tmp_cnt = cnt[:]
  cur = fact.fac(n)
  for c in tmp_cnt:
    cur = (cur * fact.fac_inv(c)) % mod

  res = 0
  for i in range(n):
    cur = (cur * fact.inv(n - i)) % mod

    res += cur * sum(tmp_cnt[:s[i]])
    res %= mod

    if tmp_cnt[s[i]] == 0: break

    cur = (cur * tmp_cnt[s[i]]) % mod
    tmp_cnt[s[i]] -= 1

  return res


print((f(s2) - f(s1) - 1) % mod)
