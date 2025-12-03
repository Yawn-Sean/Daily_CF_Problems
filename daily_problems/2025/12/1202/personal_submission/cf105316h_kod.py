class Factorial:
    def __init__(self, N, mod) -> None:
        N += 1
        self.mod = mod
        self.f = [1 for _ in range(N)]
        self.g = [1 for _ in range(N)]
        for i in range(1, N):
            self.f[i] = self.f[i - 1] * i % self.mod
        self.g[-1] = pow(self.f[-1], mod - 2, mod)
        for i in range(N - 2, -1, -1):
            self.g[i] = self.g[i + 1] * (i + 1) % self.mod

    def inv(self, n):
        return self.f[n - 1] * self.g[n] % self.mod

t = ix()
f = Factorial(10 ** 5 + 1, mod)
for i in range(t):
    n = ix()
    ans = 0
    for j in range(1, n + 1):
        ans = (ans + (n + 1) * f.inv(j + 1)) % mod
    print(ans)
