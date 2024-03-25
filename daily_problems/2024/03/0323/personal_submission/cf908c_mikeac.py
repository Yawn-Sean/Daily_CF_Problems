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
    n, r = mint()
    x = ints()
    ans = [r] * n
    r *= 2
    for i in range(n):
        for j in range(i):
            if abs(x[i] - x[j]) <= r:
                ans[i] = max(ans[i], ans[j] + math.sqrt(r * r - (x[i] - x[j]) * (x[i] - x[j])))
    print(*ans)

solve()
