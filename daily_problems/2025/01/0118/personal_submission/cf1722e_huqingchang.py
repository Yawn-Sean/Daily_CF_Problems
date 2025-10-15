def main():
    n, q = MII()
    g = [[0] * 1001 for _ in range(1001)]
    for _ in range(n):
        h, w = MII()
        g[h][w] += h * w
    for i in range(1, 1001):
        for j in range(1, 1001):
            g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1]
    for _ in range(q):
        hs, ws, hb, wb = MII()
        hb -= 1
        wb -= 1
        print(g[hb][wb] - g[hs][wb] - g[hb][ws] + g[hs][ws])


T = II()
for ii in range(T):
    # print(main())
    main()
