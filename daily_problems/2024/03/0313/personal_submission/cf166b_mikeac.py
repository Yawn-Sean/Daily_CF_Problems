import math
import sys
from bisect import bisect_left

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
    A = []
    min_x, max_x = math.inf, -math.inf
    min_idx = max_idx = -1
    for i in range(n):
        A.append(tuple(mint()))
        if A[-1][0] < min_x:
            min_x, min_idx = A[-1][0], i
        if A[-1][0] > max_x:
            max_x, max_idx = A[-1][0], i
    
    if max_idx > min_idx:
        high = A[min_idx:max_idx+1]
        low = A[max_idx:] + A[:min_idx+1]
    else:
        high = A[min_idx:] + A[:max_idx+1]
        low = A[max_idx:min_idx+1]
    low.reverse()

    m = sint()
    check = True
    for _ in range(m):
        x, y = mint()
        if not check:
            continue
        if x <= min_x or x >= max_x:
            check = False
            continue
        j = bisect_left(high, (x, y))
        x2, y2 = high[j]
        x1, y1 = high[j - 1]
        if (y2 - y1) * (x - x1) <= (y - y1) * (x2 - x1):
            check = False
            continue
        j = bisect_left(low, (x, y))
        x2, y2 = low[j]
        x1, y1 = low[j - 1]
        if (y2 - y1) * (x - x1) >= (y - y1) * (x2 - x1):
            check = False
            continue

    print("YES" if check else "NO")


solve()
