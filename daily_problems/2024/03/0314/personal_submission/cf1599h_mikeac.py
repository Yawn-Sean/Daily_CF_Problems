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
    print("?", 1, 1, flush=True)
    d1 = sint()
    print("?", 10 ** 9, 1, flush=True)
    d2 = sint()
    print("?", 1, 10 ** 9, flush=True)
    d3 = sint()
    x_mid = (10 ** 9 - d2 + d1 + 1) // 2
    print("?", x_mid, 1, flush=True)
    d4 = sint()
    print("!", d1 - d4 + 1, d4 + 1, 10 ** 9 + d4 - d2, d1 - d4 - d3 + 10 ** 9, flush=True)


solve()
