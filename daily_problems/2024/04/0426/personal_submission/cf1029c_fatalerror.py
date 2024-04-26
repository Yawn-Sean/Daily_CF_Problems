"""
区间交集由所有区间左端点最大值和右端点最小值确定。枚举删除哪个区间，计算其他区间的左右端点最值，这可以通过前后缀分解快速计算。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

MX = 10**9

n = ii()
intervals = []
for _ in range(n):
    intervals.append(lii())

leftpremax = [0] * (n+1)
rightpremin = [MX] * (n+1)
for i in range(n):
    l, r = intervals[i]
    leftpremax[i+1] = max(leftpremax[i], l)
    rightpremin[i+1] = min(rightpremin[i], r)

leftsufmax = [0] * (n+1)
rightsufmin = [MX] * (n+1)
for i in range(n-1, -1, -1):
    l, r = intervals[i]
    leftsufmax[i] = max(leftsufmax[i+1], l)
    rightsufmin[i] = min(rightsufmin[i+1], r)

ans = 0
for i in range(n):
    cur = min(rightpremin[i], rightsufmin[i+1]) - max(leftpremax[i], leftsufmax[i+1])
    ans = max(ans, cur)
print(ans)