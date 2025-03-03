import random
import sys
from bisect import bisect_left, bisect_right
from collections import defaultdict
from functools import cmp_to_key
from heapq import heappush, heappop
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x


'''
https://codeforces.com/problemset/problem/700/A
一共分cnt = (n + k - 1) // k 批次坐车
设每批次车前进时间t，相邻批次中间时间步行的人前进s，那么(cnt - 1) * s + t * v2 = L
考虑s的计算，返回的时间 tt = t * (v2 - v1) /(v1 + v2)，s = (t + tt) * v1
s = 2*v2*v1 *t//(v1 + v2)
(2 *(cnt - 1) * v2 * v1 / (v1 + v2) + v2) * t = L
'''

n, L, v1, v2, k = RII()
cnt = (n + k - 1) // k

t = L / (2 * (cnt - 1) * v2 * v1 / (v1 + v2) + v2)
ans = t + (L - t * v2) / v1 # 最后走ts坐车，剩余距离都是走路
print(ans)