import sys
from functools import cache

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

cnt = [None] * 11
for b in range(2, 11):
    length = cur = 1
    while cur <= 10 ** 18:
        length += 1
        cur *= b
    length -= 1
    cnt[b] = [[0] * (1 << b) for _ in range(length)]
    for i in range(b):
        cnt[b][0][1 << i] = 1
    for i in range(length - 1):
        for mask in range(1 << b):
            for bit in range(b):
                cnt[b][i + 1][mask ^ (1 << bit)] += cnt[b][i][mask]

def get_vals(x: int, b: int) -> list:
    res = []
    while x:
        res.append(x % b)
        x //= b
    return res

def solve() -> None:
    b, l, r = mint()
    
    def f(x: int) -> int:
        vals = get_vals(x, b)
        k = len(vals)

        ans = mask = 0

        for i in range(k - 1):
            ans += cnt[b][i][0]
            if i: ans -= cnt[b][i - 1][1]

        for i in range(k - 1, -1, -1):
            for j in range(1 if i == k - 1 else 0, vals[i]):
                ans += cnt[b][i - 1][mask ^ (1 << j)] if i else mask == 1 << j
            mask ^= 1 << vals[i]
        return ans

    print(f(r + 1) - f(l))


for _ in range(int(input())):
    solve()
