from collections import Counter


class LeastPrimeFactor:

    def __init__(self, n):
        self.N = n
        self.lpf = list(range(self.N + 1))
        for x in range(2, int(self.N ** .5) + 1):
            if self.lpf[x] == x:
                for y in range(x * x, self.N + 1, x):
                    self.lpf[y] = x

    def get_factors(self, x):
        factors = []
        while x > 1:
            p = self.lpf[x]
            x //= p
            factors.append(p)
        return factors

    def get_all_factors(self, x):
        factors = []
        while x > 1:
            p = self.lpf[x]
            x //= p
            factors.append(p)
        # print(factors)

        rets = set()
        n = len(factors)
        for i in range((1 << n)):
            x = 1
            for j in range(n):
                if i >> j & 1:
                    x *= factors[j]
            rets.add(x)
        rets = list(sorted(rets))
        return rets


import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

lpf = LeastPrimeFactor(10 ** 6 + 5)

tcn = I()
for _tcn_ in range(tcn):
    N, q = MI()
    n = N
    ss = lpf.get_factors(n)
    cnt = Counter(ss)
    ops = [LI() for _ in range(q)]
    for op in ops:
        if op[0] == 1:
            x = op[1]
            for c in lpf.get_factors(x):
                cnt[c] += 1
            d = 1
            for k, v in cnt.items():
                d *= (v + 1)
            n *= x
            YN(n % d == 0)
        else:
            cnt = Counter(ss)
            n = N
    print()
