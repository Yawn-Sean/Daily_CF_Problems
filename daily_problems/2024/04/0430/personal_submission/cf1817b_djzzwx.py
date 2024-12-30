def solve() -> None:
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)

    for st in range(n):
        if len(g[st]) < 4:
            continue
        onPath = [0] * n
        vis = [0] * n
        path = []
        def dfs(i: int, fa: int) -> bool:
            vis[i] = 1
            for j in g[i]:
                if j != fa and j == st:
                    onPath[i] = 1
                    path.append((i, j))
                    return True
            for j in g[i]:
                if vis[j] == 0 and dfs(j, i):
                    onPath[i] = 1
                    path.append((i, j))
                    return True
            return False
        if dfs(st, -1) == False:
            continue
        c = 2
        for v in g[st]:
            if c > 0 and onPath[v] == 0:
                    path.append((st, v))
                    c -= 1
        print("YES")
        print(len(path))
        for v in path:
            print(f'{v[1] + 1} {v[0] + 1}')
        return
    print("NO")



for _ in range(int(input())):
    solve()