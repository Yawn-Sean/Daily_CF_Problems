# -*- coding: UTF-8 -*-
import sys

MOD = 10**9 + 7
N = 2 * 10**5 + 5
s = [0] * N
s[1], s[2], c = 1, 3, 2
for x in range(3, N):
    c <<= 1
    if c >= MOD:
        c -= MOD
    s[x] = (s[x - 1] + (s[x - 2] << 1) + c) % MOD

it = iter(sys.stdin.buffer.read().split())
next(it)
print('\n'.join(str(s[int(x)]) for x in it))
