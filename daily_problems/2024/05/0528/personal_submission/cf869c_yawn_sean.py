# Submission link: https://codeforces.com/contest/869/submission/262943523


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

    def fac(self, n):
        return self.f[n]

    def combi(self, n, m):
        if n < m or m < 0 or n < 0: return 0
        return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod

def main():
    mod = 998244353
    fac = Factorial(5001, mod)
    a, b, c = MII()

    def f(x, y):
        ans = 0
        for i in range(min(x, y) + 1):
            ans += fac.combi(x, i) * fac.combi(y, i) % mod * fac.fac(i) % mod
            ans %= mod
        return ans

    print(f(a, b) * f(b, c) % mod * f(a, c) % mod)