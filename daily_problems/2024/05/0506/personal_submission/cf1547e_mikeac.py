import math
import sys
# from heapq import *

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
    input()
    n, k = mint()
    a = ints()
    t = ints()
    ans = [math.inf] * n
    idx = sorted(range(k), key = lambda x: a[x])

    # 935 ms
    mn, j = math.inf, 0
    for i in range(n):
        while j < k and a[idx[j]] <= i + 1:
            mn = min(mn, t[idx[j]] - a[idx[j]])
            j += 1
        if mn != math.inf:
            ans[i] = i + 1 + mn
    mn, j = math.inf, k - 1
    for i in range(n - 1, -1, -1):
        while j >= 0 and a[idx[j]] >= i + 1:
            mn = min(mn, t[idx[j]] + a[idx[j]])
            j -= 1
        if mn != math.inf:
            ans[i] = min(ans[i], mn - i - 1)

    '''
    # 1357 ms
    h = []
    for i in range(k):
        heappush(h, (t[i] + a[i], a[i]))
    heapify(h)
    left, j = math.inf, 0
    for i in range(n):
        while j < k and a[idx[j]] <= i + 1:
            left = min(left, t[idx[j]] - a[idx[j]])
            j += 1
        ans[i] = i + 1 + left
        while h and h[0][1] <= i + 1:
            heappop(h)
        if h:
            ans[i] = min(ans[i], h[0][0] - i - 1)
            '''
    print(*ans)


for _ in range(int(input())):
    solve()
