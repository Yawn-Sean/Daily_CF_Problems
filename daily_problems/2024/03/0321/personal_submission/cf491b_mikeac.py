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
    n, m = mint()
    mn_x = mn_y = math.inf
    mx_x = mx_y = -math.inf
    for _ in range(sint()):
        x, y = mint()
        mn_x = min(mn_x, x + y)
        mx_x = max(mx_x, x + y)
        mn_y = min(mn_y, x - y)
        mx_y = max(mx_y, x - y)
    
    ans, idx = math.inf, -1
    for i in range(sint()):
        x, y = mint()
        d = max(x + y - mn_x, mx_x - x - y, x - y - mn_y, mx_y - x + y)
        if d < ans:
            ans, idx = d, i + 1
    
    print(ans)
    print(idx)



solve()
