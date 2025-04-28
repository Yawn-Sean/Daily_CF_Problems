def main():
    n, m = MII()
    g = [[] for _ in range(n + 1)]
    rev_g = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = MII()
        g[u].append(v)
        rev_g[v].append(u)
    k = II()
    path = LII()
    dis = [inf] * (n + 1)
    dis[path[-1]] = 0
    dq = deque([path[-1]])
    while dq:
        a = dq.popleft()
        for ne in rev_g[a]:
            if dis[ne] == inf:
                dis[ne] = dis[a] + 1
                dq.append(ne)
    mi, mx = 0, 0
    ln = len(path)
    for i in range(1, ln - 1):
        if dis[path[i]] + 1 == dis[path[i - 1]]:
            pre = path[i - 1]
            aft = path[i]
            cnt = 0
            for ne in g[pre]:
                if dis[ne] + 1 == dis[pre]:
                    cnt += 1
                if cnt > 1:
                    break
            if cnt > 1:
                mx += 1
        else:
            mi += 1
            mx += 1
    print(mi, mx)


T = 1
for ii in range(T):
    # print(main())
    # print(ii + 1)
    main()
