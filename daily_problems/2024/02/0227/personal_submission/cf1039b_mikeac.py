import sys
from random import randint

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
    n, k = mint()
    l, r = 1, n
    while True:
        while r - l > 50:
            m = (l + r) >> 1
            print(l, m, flush=True)
            res = input()
            if res == "Yes":
                r = m
            else:
                l = m + 1
            l = max(1, l - k)
            r = min(n, r + k)
        x = randint(l, r)
        print(x, x, flush=True)
        res = input()
        if res == "Yes":
            break
        l = max(1, l - k)
        r = min(n, r + k)


solve()
