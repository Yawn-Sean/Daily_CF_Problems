import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from collections import defaultdict
from math import gcd

def solve():
    ans = 0
    mp = defaultdict(int)
    for _ in range(ii()):
        x1, y1, x2, y2 = lii()
        dx, dy = (x1-x2, y1-y2)
        g = gcd(dx, dy)
        dx, dy = dx//g, dy//g
        ans += mp.get((-dx, -dy), 0)
        mp[(dx, dy)] += 1
    return ans

for _ in range(ii()):
    print(solve())
