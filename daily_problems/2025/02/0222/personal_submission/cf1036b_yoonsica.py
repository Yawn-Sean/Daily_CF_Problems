import sys
from collections import defaultdict, deque
from itertools import accumulate
from heapq import *
from bisect import *
from types import GeneratorType
from heapq import *
from typing import List
from math import inf, gcd

RI = lambda: int(sys.stdin.readline().strip())
RF = lambda: float(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RFF = lambda: map(float, sys.stdin.readline().strip().split())
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
RFLIST = lambda: list(RFF())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x


'''
https://codeforces.com/problemset/problem/1036/B
'''
for _ in range(RI()):
    n, m, k = RII()
    if n > m:
        n, m = m, n
    if k < m:
        print(-1)
    elif (m - n) & 1:
        print(k - 1) # 全走斜线可以走n，剩余m-n上下斜线交替，如果还剩奇数，需要横着走一次
    else:
        if k & 1 != n & 1:
            print(k - 2)
        else:
            print(k)