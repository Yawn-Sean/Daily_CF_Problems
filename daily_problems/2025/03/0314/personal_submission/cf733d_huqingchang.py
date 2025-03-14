def main():
    n = II()
    res = []
    d = defaultdict(list)
    diMax = 0
    k = 1
    ans = []
    for i in range(n):
        a, b, c = sorted(LII())
        d[(b, c)].append(i)
        res.append(a)
    for ki, v in d.items():
        v.sort(key=lambda p: res[p])
        if len(v) == 1:
            tmp = res[v[0]]
            if tmp > diMax:
                k = 1
                diMax = tmp
                ans = [v[0] + 1]
        else:
            tmp = res[v[-1]] + res[v[-2]]
            tmp = min(tmp, ki[0], ki[1])
            if tmp > diMax:
                k = 2
                diMax = tmp
                ans = [v[-1] + 1, v[-2] + 1]
    print(k)
    print(*ans)



T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
