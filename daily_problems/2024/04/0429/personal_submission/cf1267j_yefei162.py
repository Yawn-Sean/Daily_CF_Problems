# -*- coding: utf-8 -*-
import sys
from collections import Counter

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

tcn = I()
for _tcn_ in range(tcn):
    n = I()
    nums = LI()
    cnt = Counter(nums)
    B = list(cnt.values())
    B.sort()


    def check(x, s):
        if x % s == 0 or x % s == s - 1:
            return True
        if x % (s - 1) == 0 or x % (s - 1) <= x // (s - 1):
            return True
        return False


    for y in range(B[0] + 1, 0, -1):
        if all(check(x, y) for x in B):
            ans = sum(x // y + min(x % y, 1) for x in B)
            break
    print(ans)
