def main():
    n, k = MII()
    a, b = MII()
    mi, mx = inf, -inf
    c = 0
    nk = n * k
    for i in [-1, 1]:
        for j in [-1, 1]:
            c = i * a + j * b
            c %= k
            if c == 0:
                c = k
            for ex in range(n):
                tmp = c + ex * k
                lc = math.lcm(nk, tmp)
                x0 = lc // tmp
                if x0 < mi:
                    mi = x0
                if x0 > mx:
                    mx = x0
    print(mi, mx)


tt = 1
for ii in range(tt):
    # print(main())
    main()
