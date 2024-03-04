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
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = mint()
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)
    col = [-1] * n
    for i in range(n):
        if col[i] != -1:
            continue
        col[i] = step = 0
        q = [i]
        while q:
            tmp = q
            q = []
            step ^= 1
            for u in tmp:
                for v in g[u]:
                    if col[v] == -1:
                        col[v] = step
                        q.append(v)
                    elif col[v] == col[u]:
                        print(-1)
                        return
    
    ans = [[] for _ in range(2)]
    for i, x in enumerate(col, 1):
        ans[x].append(i)
    for s in ans:
        print(len(s))
        print(*s)


solve()
