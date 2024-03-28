# -*- coding: utf-8 -*-
import sys
from math import gcd

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../../input.txt', 'r')
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
m = 0

x = 0
for i in range(n):
    x = gcd(x, nums[i])
    if nums[i] != 1:
        m += 1
if x > 1:
    exit(print(-1))

ans = m * m
for i in range(n):
    x = nums[i]
    for j in range(i+1, n):
        x = gcd(x, nums[j])
        if x == 1:
            ans = min(ans, m + j - i - 1)
            break
print(ans)
