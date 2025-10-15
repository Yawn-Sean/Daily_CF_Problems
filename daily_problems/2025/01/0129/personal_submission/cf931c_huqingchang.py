def main():
    n = II()
    res = LII()

    cnt = Counter(res)
    base = min(cnt.keys())
    if len(cnt) < 3:
        if base + 1 in cnt:
            print(n)
            print(*res)
            return

    a, b, c = cnt[base], cnt[base + 1], cnt[base + 2]
    mi = inf
    d = defaultdict(list)
    a_c = a - c
    x, y, z = 0, 0, 0
    for z in range(n + 1):
        x = z + a_c
        y = n - z - x
        if 0 <= x <= n and 0 <= y <= n and min(a, x) + min(b, y) + min(c, z) < mi:
            mi = min(a, x) + min(b, y) + min(c, z)
            d[mi] = [x, y, z]
    print(mi)
    ans = []
    ans.extend([base] * d[mi][0])
    ans.extend([base + 1] * d[mi][1])
    ans.extend([base + 2] * d[mi][2])
    print(*ans)


T = 1
for ii in range(T):
    # print(main())
    main()
