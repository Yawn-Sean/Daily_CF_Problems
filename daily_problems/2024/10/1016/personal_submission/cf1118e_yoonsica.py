from functools import lru_cache

import math
import sys
from collections import defaultdict, deque
from itertools import accumulate
from heapq import *
from bisect import *
from types import GeneratorType
from heapq import *
from typing import List
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RF = lambda: float(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RFF = lambda: map(float, sys.stdin.readline().strip().split())
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
RFLIST = lambda: list(RFF())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

n, k = RII()
if (k - 1) * k < n:
    print('NO')
else:
    print('YES')
    a, b = 1, 2
    while n > 0:
        print(a, b)
        n -= 1
        if n:
            print(b, a)
        else:
            break
        b += 1
        if b == k + 1:
            a += 1
            b = a + 1
        n -= 1
        
    