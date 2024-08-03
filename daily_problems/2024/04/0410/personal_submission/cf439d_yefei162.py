# -*- coding: utf-8 -*-
import bisect
import sys
from itertools import accumulate

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

n1, n2 = MI()
nums1 = LI()
nums2 = LI()

nums1.sort()
nums2.sort()
acc1 = list(accumulate(nums1, initial=0))
acc2 = list(accumulate(nums2, initial=0))

ans = 1 << 64
for x in sorted(nums1 + nums2):
    i1 = bisect.bisect_left(nums1, x)
    i2 = bisect.bisect_right(nums2, x)
    op1 = i1 * x - acc1[i1]
    op2 = acc2[-1] - acc2[i2] - (n2 - i2) * x
    ans = min(ans, op1 + op2)
print(ans)
