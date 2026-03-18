# -*- coding: UTF-8 -*-
import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()


N = 2 * 10**5 + 1

pri = []
not_prime = [False] * N
phi = [1] * N
for i in range(2, N):
    if not not_prime[i]:
        pri.append(i)
        phi[i] = i - 1
    for pri_j in pri:
        x = i * pri_j
        if x >= N:
            break
        not_prime[x] = True
        if i % pri_j == 0:
            phi[x] = phi[i] * pri_j
            break
        phi[x] = phi[i] * phi[pri_j]

f = [0] * N
for p in pri:
    i, x = 2, p << 1
    while x < N:
        f[x] += phi[i]
        i += 1
        x += p

s = list(accumulate(f))


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        l, r = map(int, input().split())
        outs[_] = str(s[r] - s[l - 1])
    print('\n'.join(outs))
