def main():
    n = II()
    t = 0
    mi = inf
    a = int(n ** 0.5)
    for i in range(max(1, a - 2), min(n, a + 2) + 1):
        if (n + i - 1) // i + i < mi:
            mi = (n + i - 1) // i + i
            t = i
    ans = []
    res = list(range(1, n + 1))
    for i in range(0, n, t):
        ans.append(res[i: i + t])
    ans = ans[::-1]
    ret = []
    for lis in ans:
        ret.extend(lis)
    print(*ret)


T = 1
for ii in range(T):
    # print(main())
    main()
