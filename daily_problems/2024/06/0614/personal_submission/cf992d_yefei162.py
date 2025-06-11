# -*- coding: utf-8 -*-
import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = 1
for _tcn_ in range(tcn):
    n, k = MI()
    A = LI()
    ans = 0
    if k == 1:
        ans += A.count(1)

    pre_sum = list(accumulate(A, initial=0))
    B = []
    for i, a in enumerate(A):
        if a == 1:
            continue
        B.append((i, a))

    m = len(B)
    i0 = 0
    for i in range(m):
        p = 1
        i1 = B[i][0]
        start = i0
        for j in range(i, i + 60):
            if j >= m: break
            if p >= 10**20: break
            p *= B[j][1]
            mi = pre_sum[B[j][0] + 1] - pre_sum[i1]
            left = pre_sum[i1] - pre_sum[i0]

            if j + 1 < m:
                right = pre_sum[B[j + 1][0]] - pre_sum[B[j][0] + 1]
                end = B[j + 1][0]
            else:
                right = pre_sum[-1] - pre_sum[B[j][0] + 1]
                end = n
            if p % k == 0:
                s = p // k
                s -= mi
                if 0 <= s <= left + right:
                    # print(A[start: end])
                    # print(B[i], B[j], s, left, right)
                    ans += min(s + 1, left + 1, right + 1, left + right - s + 1)

        i0 = B[i][0] + 1
    print(ans)
