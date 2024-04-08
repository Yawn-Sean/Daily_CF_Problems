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
    n, x, y = mint()
    for _ in range(n):
        a = sint()
        l, r = 0, min(x, y) * a
        while l < r:
            mid = (l + r) // 2
            if mid // x + mid // y >= a:
                r = mid
            else:
                l = mid + 1
        if r % x == 0 and r % y == 0:
            print("Both")
        elif r % x == 0:
            print("Vova")
        else:
            print("Vanya")

solve()
