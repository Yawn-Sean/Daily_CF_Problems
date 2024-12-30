import sys
from collections import Counter

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
    n, m, k = mint()
    row = ints()
    col = ints()
    xs = set(row)
    ys = set(col)
    on_x, on_y = [], []
    for _ in range(k):
        x, y = mint()
        if x not in xs:
            on_y.append((x, y))
        elif y not in ys:
            on_x.append((y, x))
    ans = 0
    cnt = Counter()
    on_x.sort()
    on_y.sort()
    i = j = 0
    for x in row[1:]:
        cnt.clear()
        while j < len(on_y) and on_y[j][0] < x:
            ans -= cnt[on_y[j][1]]
            cnt[on_y[j][1]] += 1
            j += 1
        ans += (j - i) * (j - i - 1) // 2
        if j == len(on_y):
            break
        i = j
    i = j = 0
    for y in col[1:]:
        cnt.clear()
        while j < len(on_x) and on_x[j][0] < y:
            ans -= cnt[on_x[j][1]]
            cnt[on_x[j][1]] += 1
            j += 1
        ans += (j - i) * (j - i - 1) // 2
        if j == len(on_x):
            break
        i = j
    print(ans)

for _ in range(int(input())):
    solve()
