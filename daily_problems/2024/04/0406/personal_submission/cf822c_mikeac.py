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
    n, x = mint()
    seg = []
    for _ in range(n):
        l, r, c = mint()
        seg.append((l, r, c))
    
    right = sorted(range(n), key=lambda x: seg[x][1])
    left = sorted(range(n), key=lambda x: seg[x][0])
    d = dict()
    ans = math.inf
    j = 0
    for i in left:
        l, r, c = seg[i]
        while j < n and seg[right[j]][1] < l:
            rl, rr, rc = seg[right[j]]
            length = rr - rl + 1
            if length not in d or rc < d[length]:
                d[length] = rc
            j += 1
        if x - r + l - 1 in d:
            ans = min(ans, c + d[x - r + l - 1])
    print(-1 if ans == math.inf else ans)

solve()
