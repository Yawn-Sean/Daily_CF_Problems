import sys
from collections import defaultdict, deque, Counter
from itertools import accumulate
from heapq import *
from bisect import *
from types import GeneratorType
from heapq import *
from typing import List
from math import inf

mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x
standard_input = True
if standard_input:
    RI = lambda: int(sys.stdin.readline().strip())
    RF = lambda: float(sys.stdin.readline().strip())
    RS = lambda: sys.stdin.readline().strip()
    RFF = lambda: map(float, sys.stdin.readline().strip().split())
    RII = lambda: map(int, sys.stdin.readline().strip().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())

else:
    RI = lambda: int(input())
    RF = lambda: float(input())
    RS = lambda: input()
    RFF = lambda: map(float, input())
    RII = lambda: map(int, input().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')
    input = lambda: fin.readline().strip()


    def print(x):
        fout.write(str(x))

n, k = RII()
a = RILIST()
l = ans = 0
while l < n:
    s = 1
    r = l
    while r < n:
        s *= a[r]
        s %= k
        if s == 0:
            break
        r += 1
    # 向前找最小满足区间[l0, r]
    l0 = r
    if r < n:
        s = 1
        while l0 >= l:
            s *= a[l0]
            s %= k
            if s == 0:
                break
            l0 -= 1
        ans += (l0 - l + 1) * (n - r)
    l = l0 + 1
print(ans)
