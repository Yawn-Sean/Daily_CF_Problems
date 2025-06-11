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
https://codeforces.com/problemset/problem/772/A

n个设备，初始电量b[i],电量消耗a[i],充电器每秒充电p，问最快有设备没电的最长时间
考虑二分
'''
eps = 10**-6
n, p = RII()
a, b = [], []
total = ts = 0
for _ in range(n):
    x, y = RII()
    a.append(x)
    b.append(y)
    total += x
    ts += y
if p >= total:
    print(-1)
    exit()

l, r = 0, ts / (total - p) + 1


def check(mid):
    # 检查是否每个设备都可以运行到mid秒才没电
    t = 0
    for i, (x, y) in enumerate(zip(a, b)):
        t += mx(0, mid * x - y)
    return mid * p >= t

ans = -1
while l + eps < r:
    mid = (l + r) / 2
    if check(mid):
        l = mid
        ans = mid
    else:
        r = mid
print(ans)