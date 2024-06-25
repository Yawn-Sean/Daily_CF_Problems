# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-28 14:30:46
# ----------------------------------------------

import sys

input = sys.stdin.readline


def inp():
    return int(input())


def inlt():
    return list(map(int, input().split()))


def insr():
    s = input()
    return list(s[: len(s) - 1])


def invr():
    return map(int, input().split())


def ins():
    return input().strip()


class Combinatorics:
    def __init__(self, n, mod):
        assert mod > n
        self.n = n + 10
        self.mod = mod

        self.perm = [1]
        self.rev = [1]
        self.inv = [0]
        self.fault = [0]

        self.build_perm()
        self.build_rev()
        self.build_inv()
        self.build_fault()
        return

    def build_perm(self):
        self.perm = [1] * (self.n + 1)  # (i!) % mod
        for i in range(1, self.n + 1):
            self.perm[i] = self.perm[i - 1] * i % self.mod
        return

    def build_rev(self):
        self.rev = [1] * (self.n + 1)  # pow(i!, -1, mod)
        self.rev[-1] = pow(
            self.perm[-1], -1, self.mod
        )  # GcdLike().mod_reverse(self.perm[-1], self.mod)
        for i in range(self.n - 1, 0, -1):
            self.rev[i] = self.rev[i + 1] * (i + 1) % self.mod  # pow(i!, -1, mod)
        return

    def build_inv(self):
        self.inv = [0] * (self.n + 1)  # pow(i, -1, mod)
        self.inv[1] = 1
        for i in range(2, self.n + 1):
            self.inv[i] = (self.mod - self.mod // i) * self.inv[self.mod % i] % self.mod
        return

    def build_fault(self):
        self.fault = [0] * (self.n + 1)  # fault permutation
        self.fault[0] = 1
        self.fault[2] = 1
        for i in range(3, self.n + 1):
            self.fault[i] = (i - 1) * (self.fault[i - 1] + self.fault[i - 2])
            self.fault[i] %= self.mod
        return

    def comb(self, a, b):
        if a < b:
            return 0
        res = (
            self.perm[a] * self.rev[b] * self.rev[a - b]
        )  # comb(a, b) % mod = (a!/(b!(a-b)!)) % mod
        return res % self.mod

    def factorial(self, a):
        res = self.perm[a]  # (a!) % mod
        return res % self.mod

    def inverse(self, n):
        res = self.perm[n - 1] * self.rev[n] % self.mod  # pow(n, -1, mod)
        return res

    def catalan(self, n):
        res = (self.comb(2 * n, n) - self.comb(2 * n, n - 1)) % self.mod
        return res


a, b, c = invr()
MOD = 998244353
my_comb = Combinatorics(5005, MOD)
ans1 = 0
for i in range(min(a, b) + 1):
    ans1 += my_comb.comb(a, i) * my_comb.comb(b, i) % MOD * my_comb.factorial(i) % MOD
ans2 = 0
for i in range(min(b, c) + 1):
    ans2 += my_comb.comb(b, i) * my_comb.comb(c, i) % MOD * my_comb.factorial(i) % MOD
ans3 = 0
for i in range(min(a, c) + 1):
    ans3 += my_comb.comb(a, i) * my_comb.comb(c, i) % MOD * my_comb.factorial(i) % MOD
ans = ans1 * ans2 % MOD * ans3 % MOD
print(ans)
