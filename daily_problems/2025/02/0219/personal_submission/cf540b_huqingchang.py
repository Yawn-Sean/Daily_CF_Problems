def main():
    n, k, p, x, y = MII()
    res = LII()
    tot = sum(res)
    res.sort()
    outs = []
    less, more = [], []
    for a in res:
        if a < y:
            less.append(a)
        else:
            more.append(a)
    if not more:
        if len(less) > n // 2:
            exit(print(-1))
        need = n // 2 - len(less) + y * (n + 1) // 2
        if need + tot > x:
            exit(print(-1))
        for _ in range(n // 2 - len(less)):
            outs.append(1)
        for _ in range((n + 1) // 2):
            outs.append(y)
        print(*outs)
        return
    if len(less) > n // 2:
        exit(print(-1))
    if len(more) >= (n + 1) // 2:
        need = n - k
        if need + tot > x:
            exit(print(-1))
        for _ in range(need):
            outs.append(1)
        print(*outs)
        return
    need = y * ((n + 1) // 2 - len(more)) + n // 2 - len(less)
    if need + tot > x:
        exit(print(-1))
    for _ in range(n // 2 - len(less)):
        outs.append(1)
    for _ in range((n + 1) // 2 - len(more)):
        outs.append(y)
    print(*outs)


T = 1
for ii in range(T):
    # print(main())
    # print(ii + 1)
    main()
