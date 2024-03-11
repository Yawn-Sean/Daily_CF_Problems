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
    s = ints()
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v, w = mint()
        g[u - 1].append((v - 1, w))
        g[v - 1].append((u - 1, w))
    
    parent = [-1] * n
    pw = [-1] * n
    q = [0]
    order = []
    while q:
        u = q.pop()
        order.append(u)
        for v, w in g[u]:
            if v == parent[u]:
                continue
            parent[v] = u
            pw[v] = w
            q.append(v)

    ans = 0
    dp0, dp1 = [0] * n, [0] * n
    for u in reversed(order):
        ans = max(ans, dp0[u] + dp1[u] + s[u])
        if parent[u] == -1:
            break
        p = parent[u]
        nw = max(0, dp0[u] + s[u] - pw[u])
        if nw > dp0[p]:
            dp0[p], dp1[p] = nw, dp0[p]
        elif nw > dp1[p]:
            dp1[p] = nw
    print(ans)

solve()
