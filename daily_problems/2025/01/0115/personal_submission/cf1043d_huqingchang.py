def main():
    n, m = MII()
    g = []
    for _ in range(m):
        g.append(LII())
    idxs = [[-1] * (n + 1) for _ in range(m)]
    for i in range(1, m):
        for j, k in enumerate(g[i]):
            idxs[i][k] = j
    ans = l = 0

    for r, x in enumerate(g[0]):
        if r > l and not all(idxs[i][x] - idxs[i][g[0][r - 1]] == 1 for i in range(1, m)):
            l = r
        ans += r - l + 1
    return ans


T = 1
for ii in range(T):
    print(main())
