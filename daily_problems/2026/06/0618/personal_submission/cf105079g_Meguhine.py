import sys
from heapq import heapify, heappushpop

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
p = list(map(lambda s: -int(s), input().split()))
tot = -sum(p)
heapify(p)
off, ans = 0, 0
for x in map(int, input().split()):
    off += x
    top = off - p[0]
    tmp = top // 2
    ans += tmp
    top -= tmp
    heappushpop(p, off - top)
print(tot + off * n - ans)
