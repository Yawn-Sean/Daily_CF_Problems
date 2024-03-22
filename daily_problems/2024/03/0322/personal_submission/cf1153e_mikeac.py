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
    
    xl = xr = -1
    for i in range(1, n):
        print('?', 1, 1, i, n, flush=True)
        res = sint()
        if res & 1:
            if xl == -1:
                xl = i
            xr = i + 1
    yl = yr = -1
    for i in range(1, n):
        print('?', 1, 1, n, i, flush=True)
        res = sint()
        if res & 1:
            if yl == -1:
                yl = i
            yr = i + 1

    if xl == -1:
        l, r = 1, n
        while l < r:
            mid = (l + r) // 2
            print('?', 1, yl, mid, yl, flush=True)
            res = sint()
            if res & 1:
                r = mid
            else:
                l = mid + 1
        xl = xr = r
    elif yl == -1:
        l, r = 1, n
        while l < r:
            mid = (l + r) // 2
            print('?', xl, 1, xl, mid, flush=True)
            res = sint()
            if res & 1:
                r = mid
            else:
                l = mid + 1
        yl = yr = r

    print('?', xl, yl, xl, yl, flush=True)
    res = sint()
    if res & 1:
        print('!', xl, yl, xr, yr, flush=True)
    else:
        print('!', xl, yr, xr, yl, flush=True)

solve()
