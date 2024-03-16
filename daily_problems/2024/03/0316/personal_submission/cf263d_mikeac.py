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
    n, m, k = mint()
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = mint()
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)
    
    parent = [-1] * n
    time = [0] * n
    time[0] = 1
    u = 0
    while True:
        for v in g[u]:
            if time[v]:
                if time[u] - time[v] >= k:
                    ans = []
                    while u != v:
                        ans.append(u + 1)
                        u = parent[u]
                    ans.append(v + 1)
                    print(len(ans))
                    print(*ans)
                    return
                continue
            parent[v] = u
            time[v] = time[u] + 1
            u = v
            break

solve()
