"""
按左端点升序、右端点降序的顺序排序。使用双指针，在移动右指针i的过程中：如果出现线段i被线段i-1包含的情况，则可以直接返回线段i；否则移动左端点j，使线段j与线段i能够连续，此时如果j与i之间存在其他线段，返回任一线段即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n = ii()
    intervals = []
    for idx in range(1, n+1):
        l, r = lii()
        intervals.append((l, r, idx))
    intervals.sort(key=lambda p: (p[0], -p[1]))

    j = 0
    for i, (l, r, idx) in enumerate(intervals):
        if i > 0 and r <= intervals[i-1][1]:
            return idx
        while intervals[j][1] < l-1:
            j += 1
        if i-j >= 2:
            return intervals[i-1][2]
    return -1

print(solve())