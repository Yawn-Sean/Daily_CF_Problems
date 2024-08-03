import sys
from functools import cmp_to_key

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
    ans = 0
    pair = []
    for _ in range(n):
        s = input()
        c1 = c2 = 0
        for c in s:
            if c == 's':
                c1 += 1
            else:
                ans += c1
                c2 += 1
        pair.append((c1, c2))
    def cmp(x, y):
        return -1 if x[0] * y[1] >= x[1] * y[0] else 1
    pair.sort(key = cmp_to_key(cmp))
    tot_c1 = 0
    for c1, c2 in pair:
        ans += tot_c1 * c2
        tot_c1 += c1
    print(ans)

solve()
