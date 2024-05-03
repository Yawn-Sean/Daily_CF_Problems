"""
原问题可表述为：求最小的 k ，使得对数组每个元素 x 进行操作 (x+k')%m (0<=k'<=k) 以后，数组单调不减。
容易知道 k 具有二段性，可以二分解决。操作元素 x 时，贪心地使 x>=pre 且尽可能小即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
lii = lambda: list(map(int, input().split()))

_, m = lii()
arr = lii()

def check(k):
    pre = 0
    for x in arr:
        if x+k < pre:
            return False
        if x > pre:
            if x+k < pre+m:
                pre = x
    return True

lo, hi = 0, m-1
while lo < hi:
    mid = (lo + hi) // 2
    if check(mid):
        hi = mid
    else:
        lo = mid + 1

print(lo)