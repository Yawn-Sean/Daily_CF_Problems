import math
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
    n, m = mint()
    mn = [math.inf] * (n + 1)
    cnt = [0] * (n + 1)
    for _ in range(m):
        a, b = mint()
        if b < a:
            b += n
        mn[a] = min(mn[a], b)
        cnt[a] += 1
    ans = [0] * n
    f = 0
    for i in range(1, n + 1):
        if cnt[i]:
            f = max(f, (cnt[i] - 1) * n + mn[i])
    for i in range(1, n + 1):
        ans[i - 1] = f - i
        if cnt[i]:
            f = max(f, cnt[i] * n + mn[i])
    print(*ans)


solve()
