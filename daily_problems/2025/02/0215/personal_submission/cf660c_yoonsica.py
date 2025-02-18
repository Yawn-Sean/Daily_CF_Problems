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
http://codeforces.com/problemset/problem/660/C

给你一个包含 n 个元素的数组 a 。 a 中的每个元素要么是 0 要么是 1 。

我们把 a 中最长的连续元素子段的长度记为 f(a) ，其中只有数字 1。为了使 f(a) 最大化，你可以将不超过 k 个 0 改为 1


思路：
最多改k个0为1，目标使全使1的子数组长度最大，求最大的f
考虑二分答案， check里面只需要对大于mid的每个下标判断以i结尾的子数组全为1，要修改多少次，只需要前缀和统计0的个数即可。
'''

n, k = RII()
a = RILIST()
cnt = [0]*(n + 1)
for i, x in enumerate(a, 1):
    cnt[i] = cnt[i - 1] + int(x == 0)

l, r = -1, n + 1


def check(mid):
    if mid > n:
        return False
    # 检查能否通过k次操作使最长连续1长度=mid
    for i in range(mid, n + 1):
        # i, i - mid + 1
        if cnt[i] - cnt[i - mid] <= k:
            return True
    return False


while l + 1 < r:
    mid = l + r >> 1
    if check(mid):
        l = mid
    else:
        r = mid


print(l)

for i in range(l, n + 1):
    # i, i - mid + 1
    if cnt[i] - cnt[i - l] <= k:
        print(' '.join(map(str, a[:i - l] + [1] * l + a[i:])))
        break
