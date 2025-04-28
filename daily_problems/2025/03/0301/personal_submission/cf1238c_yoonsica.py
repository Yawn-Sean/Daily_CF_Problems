import sys
from collections import defaultdict
from itertools import pairwise
from math import comb

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x


'''
https://codeforces.com/problemset/problem/1238/C
'''
for _ in range(RI()):
    h, n = RII()
    a = RILIST() + [0]
    ans = 0
    i = 1
    while i < n:
        if a[i] - a[i + 1] > 1:
            ans += 1
        else:
            i += 1
        i += 1
    print(ans)