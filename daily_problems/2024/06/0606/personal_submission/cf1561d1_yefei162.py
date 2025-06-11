# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())


tcn = 1
for _tcn_ in range(tcn):
    n, mod = MI()

    diff = [0] * (n + 2)
    pre_sum = [0] * (n + 2)

    for i in range(1, n + 1):
        pre_sum[i] = pre_sum[i - 1] + diff[i]
        pre_sum[i] %= mod
        cur = pre_sum[i] or 1

        diff[i + 1] += cur

        for x in range(2, n + 1):
            if i * x <= n:
                diff[i * x] += cur
                diff[i * x] %= mod
                if i * x + x <= n:
                    diff[i * x + x] -= cur
                    diff[i * x + x] %= mod
            else:
                break

    ans = pre_sum[n] % mod
    print(ans)
