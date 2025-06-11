def main():
    n, k = MII()
    a, b, c, d = MII()
    if n == 4 or k < n + 1:
        exit(print(-1))
    ans = [a, c] + [0] * (n - 4) + [d, b]
    occ = {a, b, c, d}
    p = 2
    for i in range(1, n + 1):
        if i in occ:
            continue
        ans[p] = i
        p += 1
    print(*ans)
    outs = [c, a] + ans[2: -2] + [b, d]
    print(*outs)


T = 1
for ii in range(T):
    # print(main())
    # print(ii + 1)
    main()
