# -*- coding: utf-8 -*-
import sys
from collections import defaultdict
from heapq import heappop, heappush

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())


n, k = MI()
segments = [LI() + [i] for i in range(n)]

N = 2 * 10 ** 5 + 5
cnt = [0] * N
groups = defaultdict(list)
for segment in segments:
    L, R, i = segment
    cnt[L] += 1
    cnt[R + 1] -= 1
    groups[L].append((-R, i + 1))

ans = []
h = []
for x in range(1, N):
    cnt[x] += cnt[x - 1]
    for seg in groups[x]:
        heappush(h, seg)
    while cnt[x] > k:
        R, i = heappop(h)
        R = -R
        cnt[x] -= 1
        cnt[R + 1] += 1
        ans.append(i)

print(len(ans))
print(*ans)
