import sys
from math import sqrt

RII = lambda: map(int, sys.stdin.readline().strip().split())

c, hr, hb, wr, wb = RII()
ans = 0
for i in range(int(sqrt(c)) + 1):
    if i * wr <= c:
        ans = max(ans, i * hr + (c - i * wr) // wb * hb)
    if i * wb <= c:
        ans = max(ans, i * hb + (c - i * wb) // wr * hr)
print(ans)
