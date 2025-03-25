def main():
    n = II()
    g = [[] for _ in range(n + 1)]
    edges = {}
    for i in range(1, n):
        ui, vi = MII()
        g[ui].append(vi)
        g[vi].append(ui)
        edges[(ui, vi)] = edges[(vi, ui)] = i
    color = [0] * (n + 1)
    dq = deque()
    dq.append(1)
    while dq:
        a = dq.popleft()
        used = set()
        for ne in g[a]:
            idx = edges[(a, ne)]
            if color[idx]:
                used.add(color[idx])
        tmp = 1
        for ne in g[a]:
            idx = edges[(a, ne)]
            if not color[idx]:
                while tmp in used:
                    tmp += 1
                color[idx] = tmp
                used.add(tmp)
                dq.append(ne)
    mx = 0
    d = defaultdict(list)
    for i in range(1, n):
        d[color[i]].append(i)
        mx = fmax(mx, color[i])
    print(mx)
    for i in range(1, mx + 1):
        print(len(d[i]), end=' ')
        print(*d[i])


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
