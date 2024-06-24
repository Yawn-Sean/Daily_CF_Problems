import os
import random
import sys
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby, accumulate
from bisect import bisect_left, bisect_right, insort_left, insort_right

input = sys.stdin.readline
output = lambda x: sys.stdout.write(str(x) + "\n")


I = lambda: input().rstrip("\n")
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(MII())
TMII = lambda: tuple(MII())
LI = lambda: list(I())

def solve():
    n, q = MII()
    arr = LMII()
    cnt = Counter(arr)
    new = [key * val for key, val in sorted(cnt.items())]
    indicator = sorted(cnt.keys())
    pre = list(accumulate(new, initial=0))
    s = set()
    def helper(i, j):
        if i >= j:
            return
        if i + 1 == j:
            s.add(pre[j] - pre[i])
            return
        s.add(pre[j] - pre[i])
        mid = (indicator[i] + indicator[j - 1]) // 2
        k = bisect_left(indicator, mid + 1) - 1
        helper(i, k + 1)
        helper(k + 1, j)
    helper(0, len(indicator))
    ans = list()
    for _ in range(q):
        if II() in s:
            ans.append("YES")
        else:
            ans.append("NO")
    for val in ans:
        output(val)


TC = II()

def main():
    for _ in range(TC):
        solve()

main()
