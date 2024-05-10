import sys
from heapq import *

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
    cost = [[] for _ in range(m + 1)]
    s = 0
    for _ in range(n):
        p, c = mint()
        if p != 1:
            cost[p].append(c)
            s += c
    d = [[] for _ in range(n + 1)]
    for i in range(2, m + 1):
        cost[i].sort()
        for j in range(len(cost[i]) - 1, -1, -1):
            d[len(cost[i]) - j].append(cost[i][j])
    # print(d)
    ans, cnt = s, n
    h = []
    for k in range(1, n + 1):
        for c in d[k]:
            heappush(h, c)
            s -= c
            cnt -= 1
        while h and cnt <= k:
            cnt += 1
            s += heappop(h)
        if cnt <= k:
            break
        ans = min(ans, s)
    print(ans)

solve()
