def CF436C():
    n, m, k, w = MII()
    g = [[I() for _ in range(n)] for _ in range(k)]
    edges = []

    for i in range(k):
        edges.append([n * m, 0, i + 1])
        for j in range(i + 1, k):
            diff = 0
            for x in range(n):
                for y in range(m):
                    if g[i][x][y] != g[j][x][y]:
                        diff += 1
            edges.append([diff * w, i + 1, j + 1])
    
    s = i = 0
    uf = UnionFind(k + 1)
    edges_index = sorted(range(len(edges)), key=lambda i: edges[i][0])
    path = [[] for _ in range(k + 1)]
    while k:
        w, u, v = edges[edges_index[i]]
        if not uf.connected(u, v):
            uf.union_by_size(u, v)
            path[u].append(v)
            path[v].append(u)
            s += w
            k -= 1
        i += 1
        
    ans = []
    st = [[0, -1]]
    while st:
        u, fa = st.pop()
        for v in path[u]:
            if v == fa:
                continue
            ans.append(f'{v} {u}')
            st.append([v, u])
    print(s)
    print('\n'.join(ans))
