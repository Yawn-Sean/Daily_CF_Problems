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
    x, k = mint()
    op = []
    for _ in range(k):
        n, *nums = mint()
        pres = mn = mx = pmx = 0
        for a in nums:
            pres += a
            mn = min(mn, pres)
            mx = max(mx, pres)
            if mx > pmx:
                op.append((-mn, mx - pmx))
                pmx = mx
    op.sort()
    for mn, mx in op:
        if x < mn:
            break
        x += mx
    print(x)

solve()
