# 快读板子
import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RII = lambda: map(int, sys.stdin.readline().strip().split())

n = RI()
segs = []
for _ in range(n):
    l,r = RII()
    segs.append((l,r))

left = [(0,inf)]
for l,r in segs:
    left.append((max(left[-1][0],l),min(left[-1][1],r)))

right = [(0,inf)]
for l,r in segs[::-1]:
    right.append((max(right[-1][0],l),min(right[-1][1],r)))
right = [(0,0)] + right[::-1]

ans = 0
for i,(l,r) in enumerate(segs,1):
    ans = max(ans,min(left[i - 1][1],right[i + 1][1]) - max(left[i - 1][0], right[i + 1][0]))
print(ans)