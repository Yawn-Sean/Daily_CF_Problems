"""
将每个数组贪心地分割为和为正数pres的子数组，并记录前缀和的最小值presmin。按presmin降序排序后，贪心地选择满足ans+presmin>=0的pres并累加至ans。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    ans, n = lii()
    pairs = []
    for _ in range(n):
        arr = lii()[1:]
        pres = 0
        presmin = 0
        for x in arr:
            pres += x
            presmin = min(presmin, pres)
            if pres > 0:
                pairs.append((presmin, pres))
                pres = 0
    pairs.sort(reverse=True)

    for presmin, pres in pairs:
        if ans + presmin >= 0:
            ans += pres
        else:
            break

    return ans

print(solve())