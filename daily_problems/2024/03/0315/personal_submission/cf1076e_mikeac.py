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
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = mint()
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)

    upd = [[] for _ in range(n)]
    for _ in range(sint()):
        u, d, x = mint()
        upd[u - 1].append((d, x))
    
    ans = [0] * n

    depth = [-1] * n
    cnt = [0] * n
    q = [0]
    cur = depth[0] = 0
    while q:
        u = q.pop()
        if u >= 0:
            q.append(~u)
            for d, x in upd[u]:
                cnt[depth[u]] += x
                if depth[u] + d + 1 < n:
                    cnt[depth[u] + d + 1] -= x
            cur += cnt[depth[u]]
            ans[u] = cur
            for v in g[u]:
                if depth[v] != -1:
                    continue
                depth[v] = depth[u] + 1
                q.append(v)
        else:
            u = ~u
            cur -= cnt[depth[u]]
            for d, x in upd[u]:
                cnt[depth[u]] -= x
                if depth[u] + d + 1 < n:
                    cnt[depth[u] + d + 1] += x

    print(*ans)

solve()
