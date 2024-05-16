# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
MI = lambda: map(int, input().split())

tcn = 1
for _tcn_ in range(tcn):
    X, d = MI()
    gap = d + d
    d = 32
    nums = []
    st = 1
    while X:
        # print(X)
        if X >= (2 ** d - 1):
            nums.extend([st for i in range(d)])
            st += gap
            X -= 2 ** d - 1
        else:
            d -= 1
    print(len(nums))
    print(*nums)
