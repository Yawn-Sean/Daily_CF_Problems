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
    x, y, p, q = mint()
    if p == 0:
        print(0 if x == 0 else -1)
    elif p == q:
        print(0 if x == y else -1)
    else:
        d = x * q - y * p
        if d < 0:
            ny = y + (-d + q - p - 1) // (q - p)
            ans = (ny + q - 1) // q * q - y
            print(ans)
        else:
            ny = y + (d + p - 1) // p
            ans = (ny + q - 1) // q * q - y
            print(ans)

for _ in range(int(input())):
    solve()
