def main():
    n, m = MII()
    ops = []
    for _ in range(m):
        ops.append(LII())
    ans = [10 ** 9] * (n + 1)
    diff = [0] * (n + 1)
    for t, l, r, x in ops:
        if t == 1:
            for j in range(l, r + 1):
                diff[j] += x
        else:
            for j in range(l, r + 1):
                ans[j] = min(ans[j], x - diff[j])
    tmp = ans[::]
    for t, l, r, x in ops:
        if t == 1:
            for j in range(l, r + 1):
                tmp[j] += x
        else:
            mx = -inf
            for j in range(l, r + 1):
                mx = max(mx, tmp[j])
            if mx != x:
                exit(print('NO'))
    print('YES')
    print(*ans[1:])


T = 1
for ii in range(T):
    # print(main())
    main()
