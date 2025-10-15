import random
import sys
from bisect import bisect_left, bisect_right
from collections import defaultdict
from functools import cmp_to_key
from heapq import heappush, heappop
from math import inf, sqrt

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
求连接两个圆的第三个圆的最小半径
要考虑两个圆的位置关系
'''
# print((sqrt(2) * 20 - 6) /2)
x, y, r = RII()
x1, y1, r1 = RII()

if r < r1:
    x, y, r, x1, y1, r1 = x1, y1, r1, x, y, r

t = (x - x1)*(x - x1) + (y - y1) * (y - y1)
if t >= (r + r1) * (r + r1): # 不相交
    print((sqrt(t) - r - r1) / 2)
else:
    if t < (r - r1) * (r - r1): # 包含
        print((r - r1 - sqrt(t)) / 2)
    else:
        print(0) # 相交