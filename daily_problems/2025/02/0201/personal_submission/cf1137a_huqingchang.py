def main():
    m, n = MII()
    res = []
    for _ in range(m):
        res.append(LII())
    rows, cols = [], []
    for r in res:
        rows.append(sorted(set(r)))
    for c in zip(*res):
        cols.append(sorted(set(c)))
    ans = [[0] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            x = res[i][j]
            more1, more2 = len(rows[i]) - bisect.bisect_right(rows[i], x), len(cols[j]) - bisect.bisect_right(cols[j], x)
            less1, less2 = bisect.bisect_left(rows[i], x), bisect.bisect_left(cols[j], x)
            ans[i][j] = 1 + max(more1, more2) + max(less1, less2)
    for r in ans:
        print(*r)


T = 1
for ii in range(T):
    # print(main())
    main()
