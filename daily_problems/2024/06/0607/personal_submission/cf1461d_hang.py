
from itertools import accumulate
from collections import defaultdict
import bisect
def main():
    n,q = map(int,input().split())
    a = list(map(int,input().split()))
    s = []
    for i in range(q):
        s.append(int(input()))
    a.sort()
    pre = list(accumulate(a, initial=0))
    m = defaultdict(bool)
    g = [(0, n - 1)]
    while g:
        xg = []
        for l,r in g:
            m[pre[r + 1] - pre[l]] = True
            mid = (a[l] + a[r]) // 2
            if a[l] != a[r]:
                z = bisect.bisect_right(a, mid)
                xg.append((l, z - 1))
                xg.append((z, r))
        g = xg
    for i in s:
        if m[i]:
            print("Yes")
        else:
            print("No")

t = int(input())
for _ in range(t):
    main()