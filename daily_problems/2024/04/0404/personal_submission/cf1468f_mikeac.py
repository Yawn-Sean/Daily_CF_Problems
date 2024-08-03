import math
import sys
from collections import Counter

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
    cnt = Counter()
    ans = 0
    for _ in range(n):
        x, y, u, v = mint()
        u -= x
        v -= y
        g = math.gcd(u, v)
        u //= g
        v //= g
        ans += cnt[(-u, -v)]
        cnt[(u, v)] += 1
    print(ans)


for _ in range(int(input())):
    solve()
