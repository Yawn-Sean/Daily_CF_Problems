# -*- coding : utf-8 -*-
import math
import sys
from collections import Counter

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

tcn = I()
for _tcn_ in range(tcn):
    n = I()
    persons = [LI() for _ in range(n)]
    ans = 0
    cnt = Counter()
    for x, y, u, v in persons:
        x -= u
        y -= v
        d = math.gcd(x, y)
        x //= d
        y //= d
        cnt[(x, y)] += 1
        ans += cnt[(-x, -y)]
    print(ans)
