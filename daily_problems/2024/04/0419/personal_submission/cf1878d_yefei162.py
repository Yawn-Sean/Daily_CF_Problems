# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = I()
for _tcn_ in range(tcn):
    n, k = MI()
    s = list(input())
    L = LGMI()
    R = LGMI()
    q = I()
    X = LGMI()

    hst = [-1] * n
    for i in range(k):
        for j in range(L[i], R[i] + 1):
            hst[j] = i

    flag = [0] * (n + 1)
    for x in X:
        idx = hst[x]
        a = min(x, L[idx] + R[idx] - x)
        b = max(x, L[idx] + R[idx] - x)
        # print(L[idx], a, b, R[idx])
        flag[a] += 1
        if b + 1 <= R[idx]:
            flag[b + 1] -= 1

    acc = [0] * n
    for i in range(k):
        acc[L[i]] = flag[L[i]]
        for j in range(L[i] + 1, R[i] + 1):
            acc[j] = acc[j - 1] + flag[j]

    rets = ['' for _ in range(n)]

    for i in range(k):
        for j in range(L[i], R[i] + 1):
            if acc[j] % 2:
                rets[j] = s[R[i] + L[i] - j]
            else:
                rets[j] = s[j]
    print(''.join(rets))
