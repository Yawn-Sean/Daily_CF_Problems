def main():

    n, m = MII()
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = MII()
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
    vis = [0] * n

    def bfs(node):
        vis[node] = 1
        dq = deque([[node, 1]])
        while dq:
            a, flag = dq.popleft()
            for ne in g[a]:
                if vis[ne]:
                    if vis[ne] == flag:
                        exit(print(-1))
                else:
                    vis[ne] = 3 - flag
                    dq.append([ne, vis[ne]])

    for i in range(n):
        if vis[i] == 0:
            bfs(i)
    ans1, ans2 = [], []
    for i, j in enumerate(vis):
        if j == 1:
            ans1.append(i + 1)
        else:
            ans2.append(i + 1)
    print(len(ans1))
    print(*ans1)
    print(len(ans2))
    print(*ans2)


T = 1
for ii in range(T):
    # print(main())
    main()
