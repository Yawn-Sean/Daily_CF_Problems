# -*- coding: utf-8 -*-

import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 10 ** 9 + 9

n, a, b, k = MI()
s = input()

# 计算首项a0
a0 = 0
for i in range(k):
    if s[i] == '+':
        a0 += pow(a, n - i, mod) * pow(b, i, mod)
    else:
        a0 -= pow(a, n - i, mod) * pow(b, i, mod)
# print(a0)

# 等比求和
q = pow(a, -k, mod) * pow(b, k, mod) % mod
m = (n + 1) // k

if q != 1:
    rst = a0 * (pow(q, m, mod) - 1) * pow(q - 1, -1, mod)
    rst %= mod
else:
    rst = a0 * m
    rst %= mod

print(rst)
