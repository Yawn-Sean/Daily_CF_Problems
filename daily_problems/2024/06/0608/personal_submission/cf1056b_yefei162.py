# -*- coding : utf-8 -*-

import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())

tcn = 3
for _tcn_ in range(tcn):
    n, m = MI()
    c1 = n // m
    c2 = n % m
    ans = 0
    for i in range(1, m + 1):
        for j in range(1, m + 1):
            if (i * i + j * j) % m == 0:
                ans += c1 * c1
    for i in range(1, c2 + 1):
        for j in range(1, m + 1):
            if (i * i + j * j) % m == 0:
                ans += c1 * 2
    for i in range(1, c2 + 1):
        for j in range(1, c2 + 1):
            if (i * i + j * j) % m == 0:
                ans += 1
    print(ans)
