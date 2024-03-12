import sys
from collections import deque

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
    p = ints()
    a = ints()
    g = [[] for _ in range(n)]
    for i, x in enumerate(p, 1):
        g[x - 1].append(i)
        if a[i] != -1:
            if a[x - 1] == -1:
                a[x - 1] = a[i]
            else:
                a[x - 1] = min(a[x - 1], a[i])
    q = deque([(0, 0)])
    while q:
        u, s = q.popleft()
        if a[u] == -1:
            a[u] = 0
        elif a[u] < s:
            print(-1)
            return
        else:
            s, a[u] = a[u], a[u] - s
        for v in g[u]:
            q.append((v, s))
    print(sum(a))

solve()
