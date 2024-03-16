import math
import sys
from collections import Counter
from random import getrandbits

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n = sint()
    point = []
    for _ in range(n):
        point.append(tuple(mint()))
    ans = 0
    cnt = Counter()
    h = getrandbits(32)
    # MOD = 998244353
    for i, (x1, y1) in enumerate(point):
        for j in range(i + 1, n):
            x2, y2 = point[j]
            # r1, r2 = y2 - y1, x2 - x1
            r1, r2 = y2 + y1, x2 + x1
            if r2 < 0:
                r1 = -r1
                r2 = -r2
            # g = math.gcd(r1, r2)
            # r1 //= g
            # r2 //= g
            # ans += cnt[(r1, r2, g)]
            # cnt[(r1, r2, g)] += 1
            hash = r1 * h + r2
            ans += cnt[hash]
            cnt[hash] += 1
    # print(ans // 2)
    print(ans)


solve()
