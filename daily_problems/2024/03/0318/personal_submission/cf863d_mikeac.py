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
    n, q, m = mint()
    nums = ints()
    qry = [tuple(mint()) for _ in range(q)]
    idx = [x - 1 for x in ints()]
    for op, l, r in qry[::-1]:
        l -= 1
        r -= 1
        for i, x in enumerate(idx):
            if x < l or x > r:
                continue
            if op == 1:
                x -= 1
                if x < l:
                    x = r
            else:
                x = l + r - x
            idx[i] = x
    print(*[nums[i] for i in idx])
    

solve()
