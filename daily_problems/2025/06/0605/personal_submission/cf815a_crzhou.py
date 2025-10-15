n, m = MII()
g = []
for _ in range(n):
    g.append(LII())

if n > m:
    ans = []
    for j in range(m):
        mi = min([g[i][j] for i in range(n)])
        if mi:
            for i in range(n):
                g[i][j] -= mi
            ans.append(("col", j + 1, mi))
    for i in range(n):
        mi = min(g[i])
        if mi:
            for j in range(m):
                g[i][j] -= mi
            ans.append(("row", i + 1, mi))

    for i in range(n):
        for j in range(m):
            if g[i][j] != 0:
                print(-1)
                sys.exit(0)

    res = []
    for op in ans:
        o, idx, v = op
        for _ in range(v):
            res.append((o, idx))
    print(len(res))
    for op in res:
        print(*op)
    
else:
    ans = []
    for i in range(n):
        mi = min(g[i])
        if mi:
            for j in range(m):
                g[i][j] -= mi
            ans.append(("row", i + 1, mi))

    for j in range(m):
        mi = min([g[i][j] for i in range(n)])
        if mi:
            for i in range(n):
                g[i][j] -= mi
            ans.append(("col", j + 1, mi))

    for i in range(n):
        for j in range(m):
            if g[i][j] != 0:
                print(-1)
                sys.exit(0)

    res = []
    for op in ans:
        o, idx, v = op
        for _ in range(v):
            res.append((o, idx))
    print(len(res))
    for op in res:
        print(*op)
        
