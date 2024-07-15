# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())

tcn = 1
for _tcn_ in range(tcn):
    N = I()
    nums = []
    x = 1
    n = N
    while n:
        nums += [x] * ((n + 1) // 2)
        n -= ((n + 1) // 2)
        x *= 2
    if len(nums) >= 2:
        nums[-1] = N // nums[-2] * nums[-2]
    print(*nums)
