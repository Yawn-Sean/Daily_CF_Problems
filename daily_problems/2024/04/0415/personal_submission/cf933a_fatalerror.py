"""
寻找"1...2...1...2..."模式的最长子序列，状态机DP即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n = ii()
    arr = lii()
    dp1, dp12, dp121, dp1212 = 0, 0, 0, 0
    for x in arr:
        if x == 1:
            dp1 += 1
            dp12 = max(dp12, dp1)
            dp121 += 1
            dp1212 = max(dp1212, dp121)
        else:
            dp12 += 1
            dp121 = max(dp121, dp12)
            dp1212 += 1
    return dp1212

print(solve())