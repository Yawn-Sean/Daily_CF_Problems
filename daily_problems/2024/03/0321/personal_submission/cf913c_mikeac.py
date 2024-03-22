import math
import sys

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
    n, l = mint()
    c = ints()
    mx = l.bit_length()
    if mx > n:
        c += [math.inf] * (mx - n)
    for i in range(1, len(c)):
        c[i] = min(c[i], c[i - 1] * 2)
    ans = 0
    for i in range(l.bit_length()):
        ans = min(ans, c[i])
        ans += c[i] * ((l >> i) & 1)
    for i in range(l.bit_length(), n):
        ans = min(ans, c[i])
    print(ans)


solve()
