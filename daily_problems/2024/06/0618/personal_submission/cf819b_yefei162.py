# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(GMI())


tcn = 1
for _tcn_ in range(tcn):
    n = I()
    A = LGMI()

    d2 = [0] * (2 * n + 1)
    d = [0] * (2 * n + 1)
    f = [0] * (2 * n + 1)

    for i, a in enumerate(A):

        L1, R1 = n - 1 - i, n - 1 - i + a
        L2, R2 = R1 + 1, L1 + n - 1
        f[L1] += R1 - L1 + 1
        d2[L1] -= 1
        d2[R1 + 1] += 1
        d2[L2] += 1
        d2[R2 + 1] -= 1
        f[R2 + 1] -= R2 - L2 + 1

    for i in range(n * 2):
        if i > 0:
            d[i] += d[i - 1] + d2[i]
        else:
            d[i] = d2[i]

    for i in range(n * 2):
        if i > 0:
            f[i] += f[i - 1] + d[i]
        else:
            f[i] += d[i]

    ans = [0] * n
    ans[0] = f[n - 1]
    for i in range(n - 1):
        ans[i + 1] = f[n + i] + f[i]

    print(min(ans), ans.index(min(ans)))
