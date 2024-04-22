# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

n, k = MI()
segments = [LI() for _ in range(n)]
segments.sort(key=lambda x: x[0])

segments2 = sorted(segments, key=lambda x: x[1])

hst = dict()

ans = 1 << 31
i = 0
for j in range(n):
    while i < n and segments2[i][1] < segments[j][0]:
        d = segments2[i][1] - segments2[i][0] + 1
        if d not in hst:
            hst[d] = segments2[i][2]
        else:
            hst[d] = min(hst[d], segments2[i][2])
        i += 1
    d1 = segments[j][1] - segments[j][0] + 1
    d2 = k - d1
    if d2 in hst:
        ans = min(ans, hst[d2] + segments[j][2])
print(ans if ans < 1 << 31 else -1)
