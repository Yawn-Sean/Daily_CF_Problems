import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())

tcn = 1
for _tcn_ in range(tcn):
    n = I()
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        g[u].append(v)
        g[v].append(u)

    parent = [-1] * n
    depth = [0] * n
    stk = [0]
    dfs = []
    color = [1] * n
    while stk:
        x = stk.pop()
        dfs.append(x)
        for y in g[x]:
            if parent[x] != y:
                stk.append(y)
                parent[y] = x
                color[y] = 1 ^ color[x]

    sz = [0] * n
    for x in dfs[::-1]:
        sz[x] += 1
        fa = parent[x]
        if fa >= 0:
            sz[fa] += sz[x]

    tot = 0
    for x in dfs[::-1]:
        fa = parent[x]
        if fa >= 0:
            tot += sz[x] * (n - sz[x])

    c0 = color.count(0)
    c1 = color.count(1)

    ans = (tot + c0 * c1) // 2
    print(ans)
