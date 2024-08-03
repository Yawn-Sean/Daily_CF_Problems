# -*- coding: utf-8 -*-
import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353


def prime_factor(num):
    # 复杂度sqrt(n)。可以处理1e12
    factors = []
    i = 2
    while i * i <= num:
        if num % i == 0:
            factors.append(i)
            num = num // i
        else:
            i += 1
    if num > 1:
        factors.append(num)
    return factors


def f(n, x):
    # 求n! 里面有多少个质因子x
    # 复杂度log(n)

    c = 0
    y = x
    while y <= n:
        c += n // y
        y *= x
    return c


tcn = 1
for _tcn_ in range(tcn):
    n, b = MI()
    factors = prime_factor(b)
    cnt = Counter(factors)
    ans = 1 << 64
    for k, v in cnt.items():
        c = f(n, k)
        ans = min(ans, c // v)
    print(ans)
