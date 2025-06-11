from bisect import bisect_left, bisect_right
from itertools import accumulate, pairwise
import sys
input = lambda: sys.stdin.readline().strip()

_ = int(input())
s = sorted(list(set(map(int, input().split()))))
n = len(s)
ls = [l2 - l1 for l1, l2 in pairwise(s)]
ls.append(10 ** 18 + 1)
ls.sort()
pre = list(accumulate(ls, initial=0))

res = []
q = int(input())
for i in range(q):
    l, r = map(int, input().split())
    d = r - l + 1
    p = bisect_left(ls, d)
    res.append(pre[p] + (n - p) * d)

print(*res, sep=' ')
