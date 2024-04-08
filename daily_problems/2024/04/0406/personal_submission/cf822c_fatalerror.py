import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from collections import defaultdict
from bisect import bisect_left, bisect_right
inf = 1 << 31

def solve():
    n, tot = lii()
    mp = defaultdict(list)
    for _ in range(n):
        l, r, cost = lii()
        mp[r-l+1].append((l, cost))

    premins = defaultdict(list)
    sufmins = defaultdict(list)
    for dur, vals in mp.items():
        m = len(vals)
        vals.sort()
        premin = [inf] * (m+1)
        sufmin = [inf] * (m+1)
        for i in range(m):
            premin[i+1] = min(premin[i], vals[i][1])
        for i in range(m-1, -1, -1):
            sufmin[i] = min(sufmin[i+1], vals[i][1])
        premins[dur] = premin
        sufmins[dur] = sufmin

    ans = inf
    for dur1, vals1 in mp.items():
        dur2 = tot - dur1
        if dur2 not in mp:
            continue
        vals2 = mp[dur2]
        premin = premins[dur2]
        sufmin = sufmins[dur2]
        for l1, cost1 in vals1:
            i1 = bisect_right(vals2, (l1-dur2, inf))
            i2 = bisect_left(vals2, (l1+dur1, 0))
            ans = min(ans, min(premin[i1], sufmin[i2]) + cost1)

    return ans if ans < inf else -1


print(solve())
