"""
所求即 n! 包含多少个因子 b 。对 b 质因数分解，对每个质因数及其幂次 p^c ，计算 n! 包含多少个 p^c ，取所有结果最小值即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
lii = lambda: list(map(int, input().split()))

n, b = lii()

ans = 10**18
for p in range(2, b+1):
    if p*p > b:
        break
    if b % p != 0:
        continue
    c = 0
    while b % p == 0:
        b //= p
        c += 1
    res = 0
    power = p
    while n >= power:
        res += n // power
        power *= p
    ans = min(ans, res//c)

if b != 1:
    res = 0
    power = b
    while n >= power:
        res += n // power
        power *= b
    ans = min(ans, res)

print(ans)