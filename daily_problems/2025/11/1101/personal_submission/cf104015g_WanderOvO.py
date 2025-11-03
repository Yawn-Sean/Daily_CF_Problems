"""
期望的线性性
"""

import sys

input = lambda: sys.stdin.readline().strip()

n, q = map(int, input().split())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7
inv2 = pow(2, -1, mod)
res = [0 for _ in range(n + 1)]

c = 0
for i in range(len(a) - 1, -1, -1):
    val = a[i]
    res[val] += c * inv2 % mod
    res[val] %= mod
    c = (c + val) * inv2 % mod

res[1] += c
res[1] %= mod

for i in range(1, n + 1):
    print(res[i])
