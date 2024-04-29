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
    edges = []
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v, w = mint()
        u -= 1
        v -= 1
        edges.append([u, v, w])
        g[u].append(v)
        g[v].append(u)
    
    parent = [-1] * n
    size = [1] * n
    q = [0]
    order = []
    while q:
        u = q.pop()
        order.append(u)
        for v in g[u]:
            if v == 0 or v == parent[u]:
                continue
            parent[v] = u
            q.append(v)

    for u in order[::-1]:
        if parent[u] != -1:
            size[parent[u]] += size[u]
    
    s = [0] * (n - 1)
    tot = 0

    for i, (u, v, w) in enumerate(edges):
        cnt1 = size[u] if parent[u] == v else size[v]
        cnt2 = n - cnt1
        if cnt2 > 1:
            s[i] += cnt1 * cnt2 * (cnt2 - 1) // 2
        if cnt1 > 1:
            s[i] += cnt1 * (cnt1 - 1) * cnt2 // 2
        tot += s[i] * w
    
    prob = n * (n - 1) * (n - 2) // 6
    for _ in range(sint()):
        i, w = mint()
        i -= 1
        tot -= (edges[i][2] - w) * s[i]
        edges[i][2] = w
        print(tot * 2 / prob)

solve()
