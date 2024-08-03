"""
arr[i] 可以由上至下每秒高度减 1 ，在 arr[i] 秒时清零；也可以在左侧/右侧清零后，在下一秒直接清零。
计算 arr[i] 从上/从左/从右消除的最短时间，所有最短时间取最大值即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from itertools import accumulate

n = ii()
arr = lii()
arr[0] = arr[-1] = 1
cmp = lambda a, b: a+1 if a+1 < b else b
arr = list(accumulate(arr, cmp))
arr = list(accumulate(reversed(arr), cmp))
print(max(arr))