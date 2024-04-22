# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

a, b = MI()

n = 0
while (n + 1) * (n + 2) // 2 <= a + b:
    n += 1
nums1 = []
nums2 = []
for i in range(n, 0, -1):
    if a >= i:
        a -= i
        nums1.append(i)
    else:
        nums2.append(i)
print(len(nums1))
print(*nums1)
print(len(nums2))
print(*nums2)
