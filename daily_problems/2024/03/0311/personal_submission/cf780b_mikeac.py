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
    x = ints()
    v = ints()

    esp = 10 ** -7
    l, r = 0, 10 ** 9
    # l, r = 1e-9, 1e9
    while r - l > esp:
        mid = (l + r) / 2
        # mid = (l * r) ** 0.5
        mxl, mnr = 0, 1e9
        for i in range(n):
            mxl = max(mxl, x[i] - v[i] * mid)
            mnr = min(mnr, x[i] + v[i] * mid)
        if mnr >= mxl:
            r = mid
        else:
            l = mid
    print(r)

solve()
