def main():
    n, m, r = MII()
    dis = [[[inf] * n for _ in range(n)] for _ in range(n - 1)]
    for _ in range(m):
        g = [LII() for _ in range(n)]
        for k in range(n):
            for u in range(n):
                for v in range(n):
                    g[u][v] = fmin(g[u][k] + g[k][v], g[u][v])
        for u in range(n):
            for v in range(n):
                dis[0][u][v] = fmin(dis[0][u][v], g[u][v])
    for i in range(1, n - 1):
        for u in range(n):
            for mid in range(n):
                for v in range(n):
                    dis[i][u][v] = fmin(dis[i][u][v], dis[i - 1][u][mid] + dis[0][mid][v])
    for _ in range(r):
        s, t, ki = MII()
        s -= 1
        t -= 1
        print(dis[fmin(ki, n - 2)][s][t])


T = 1
for ii in range(T):
    # print(ii)
    # print(main())
    main()
