import sys
input = lambda: sys.stdin.readline().rstrip()

class Factorial:
    def __init__(self, N, mod):
        N += 1
        self.mod = mod
        self.fact = [1] * N
        self.infact = [1] * N
        for i in range(1, N):
            self.fact[i] = self.fact[i - 1] * i % self.mod
        self.infact[N - 1] = pow(self.fact[N - 1], self.mod - 2, self.mod)
        for i in range(N - 2, 0, -1):
            self.infact[i] = self.infact[i + 1] * (i + 1) % self.mod

    def C(self, a, b):
        if a < b or a < 0 or b < 0: return 0
        return self.fact[a] * self.infact[b] % self.mod * self.infact[a - b] % self.mod


def soviet():
    n, k = map(int, input().split())
    n -= 1
    mod = 998244353

    f = Factorial(n * 2, mod)

    ans = 0
    for i in range(n - k - 1, n + k + 1):
        ans = (ans + f.C(2 * n, i)) % mod

    print(ans)


soviet()