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
    n = sint()
    A = ints()
    B = ints()
    ans, mx, mn = 0, -math.inf, math.inf
    for a, b in zip(A, B):
        ans += abs(a - b)
        mx = max(mx, min(a, b))
        mn = min(mn, max(a, b))
    
    if mx > mn:
        ans += (mx - mn) * 2
    print(ans)

for _ in range(int(input())):
    solve()