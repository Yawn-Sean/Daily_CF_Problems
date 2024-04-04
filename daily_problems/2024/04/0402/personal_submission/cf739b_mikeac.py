import sys
from bisect import bisect_left

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
    a = ints()
    p = [-1] * n
    w = [-1] * n
    child = [[] for _ in range(n)]
    for i in range(1, n):
        p[i], w[i] = mint()
        p[i] -= 1
        child[p[i]].append(i)
    ans = [0] * n
    depth = [0] * n
    order = []
    pre_dep = []
    q = [0]
    while q:
        u = q.pop()
        if u >= 0:
            pre_dep.append((depth[u], u))
            up = bisect_left(pre_dep, (depth[u] - a[u], 0))
            if u:
                ans[p[u]] += 1
            if pre_dep[up][1]:
                ans[p[pre_dep[up][1]]] -= 1
            order.append(u)
            q.append(~u)
            for v in child[u]:
                depth[v] = depth[u] + w[v]
                q.append(v)
        else:
            pre_dep.pop()
    for u in order[:0:-1]:
        ans[p[u]] += ans[u]
    print(*ans)

solve()
