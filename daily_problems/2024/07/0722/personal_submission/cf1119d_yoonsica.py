import sys
from bisect import bisect_right
from itertools import accumulate

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())

n = RI()
a = RILIST()
a = sorted(set(a))
diff = []
n = len(a)
for i in range(n - 1):
    diff.append(a[i + 1] - a[i] - 1)
diff.sort()
s = [0] + list(accumulate(diff))
ans = []
for _ in range(RI()):
    l, r = RII()
    r -= l
    idx = bisect_right(diff, r)
    ans.append(s[idx] + (len(diff) - idx)*r + r + n)
print(' '.join(map(str, ans)))

