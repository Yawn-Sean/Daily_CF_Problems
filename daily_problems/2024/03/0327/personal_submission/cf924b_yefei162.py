# -*- coding: utf-8 -*-
import sys
from bisect import bisect_right

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

n, mx = MI()
nums = LI()

mx_eta = -1
for i in range(n):
    j = bisect_right(nums, nums[i] + mx) - 1
    if j - i >= 2:
        mx_eta = max(mx_eta, (nums[j] - nums[i + 1]) / (nums[j] - nums[i]))
print(mx_eta)
