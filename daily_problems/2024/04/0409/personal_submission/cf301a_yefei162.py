# -*- coding: utf-8 -*-

import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n = I()
nums = LI()
neg = zero = 0

for i in range(2 * n - 1):
    if nums[i] < 0:
        neg += 1
    elif nums[i] == 0:
        zero += 1

nums = [abs(x) for x in nums]
nums.sort()
# print(nums, neg)

if zero:
    tot = sum(abs(x) for x in nums)
else:
    neg = neg % n
    if neg % 2 and n % 2 == 0:
        tot = sum(abs(x) for x in nums[1:]) - nums[0]
    else:
        tot = sum(abs(x) for x in nums)

print(tot)
