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
    point = [tuple(mint()) for _ in range(n)]
    ans = math.inf
    for i, (x, y) in enumerate(point):
        x1, y1 = point[i - 1]
        x2, y2 = point[(i + 1)%n]
        dx1 = x - x1
        dy1 = y - y1
        dx2 = x2 - x
        dy2 = y2 - y
        dx = x2 - x1
        dy = y2 - y1
        ans = min(ans, abs(dx1 * dy2 - dy1 * dx2) / math.sqrt(dx * dx + dy * dy) / 2)
    print(ans)

solve()
