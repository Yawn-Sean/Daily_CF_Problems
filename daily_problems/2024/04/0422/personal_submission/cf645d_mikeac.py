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
    deg = [0] * n
    for i in range(1, m + 1):
        u, v = mint()
        g[u - 1].append((v - 1, i))
        deg[v - 1] += 1

    q = [i for i in range(n) if deg[i] == 0]
    order = []
    if len(q) != 1:
        print(-1)
        return
    ans = 0
    while q:
        if len(q) != 1:
            print(-1)
            return
        u = q.pop()
        order.append(u)
        for v, i in g[u]:
            deg[v] -= 1
            if deg[v] == 0:
                q.append(v)
                ans = max(ans, i)
    print(ans)

    '''
    edges = []
    for _ in range(m):
        edges.append(tuple(mint()))
    
    def check(k: int) -> bool:
        g = [[] for _ in range(n)]
        deg = [0] * n
        for i in range(k):
            u, v = edges[i]
            g[u - 1].append(v - 1)
            deg[v - 1] += 1
        q = [i for i in range(n) if deg[i] == 0]
        if len(q) != 1:
            return False
        while q:
            if len(q) != 1:
                return False
            u = q.pop()
            for v in g[u]:
                deg[v] -= 1
                if deg[v] == 0:
                    q.append(v)
        return True
    
    l, r = 1, m
    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            r = mid - 1
        else:
            l = mid + 1
    
    print(l if l <= m else -1)
    '''

solve()
