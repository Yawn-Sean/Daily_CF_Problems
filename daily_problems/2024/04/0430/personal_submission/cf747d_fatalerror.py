"""
数组分为连续的负区间和非负区间。将 k 先应用于所有负区间；再贪心地按区间长度应用于非负区间，每次应用会连接前后两端负区间、从而使答案 -2 。需要特殊处理开头和结尾的非负区间。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n, k = lii()
    arr = lii()

    i = 0
    while i < n and arr[i] >= 0:
        i += 1
    if i == n:
        return 0

    ans = 0
    gaps = []
    end = 0
    while i < n:
        while i < n and arr[i] < 0:
            k -= 1
            i += 1
        ans += 2
        gap = 0
        while i < n and arr[i] >= 0:
            gap += 1
            i += 1
        if i < n:
            gaps.append(gap)
        else:
            end = gap
    if k < 0:
        return -1

    gaps.sort()
    for gap in gaps:
        if k - gap >= 0:
            ans -= 2
            k -= gap
        else:
            break
    if k >= end:
        ans -= 1
    return ans

print(solve())
