# -*- coding: utf-8 -*-

import sys
from heapq import heapify, heappop

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

tcn = 1
for _tcn_ in range(tcn):
    n, k = MI()
    temperatures = LI()
    neg = sum(int(temperature < 0) for temperature in temperatures)
    if neg > k:
        exit(print(-1))

    groups = [[]]
    for temperature in temperatures:
        if not groups[-1]:
            groups[-1].append(temperature)
        else:
            if temperature < 0:
                if groups[-1][-1] < 0:
                    groups[-1].append(temperature)
                else:
                    groups.append([temperature])
            else:
                if groups[-1][-1] >= 0:
                    groups[-1].append(temperature)
                else:
                    groups.append([temperature])
    # print(groups)

    if groups[0][0] >= 0:
        groups.pop(0)

    ops = len(groups)
    nums = []
    for group in groups:
        if group[0] >= 0:
            nums.append(len(group))
        else:
            k -= len(group)
    # print(nums, k)
    if nums:
        if groups[-1][0] >= 0:
            last = nums.pop()
            heapify(nums)
            while nums and nums[0] <= k:
                k -= heappop(nums)
                ops -= 2

            if last <= k:
                ops -= 1
        else:
            heapify(nums)
            while nums and nums[0] <= k:
                k -= heappop(nums)
                ops -= 2

    print(ops)
