def main():
    n = II()
    s = []
    pro_s = []
    for _ in range(n):
        si, gi = MII()
        s.append(si)
        pro_s.append(si + gi)
    for i in range(1, n):
        pro_s[i] = fmin(pro_s[i], pro_s[i - 1] + 1)
    for i in range(n - 2, -1, -1):
        pro_s[i] = fmin(pro_s[i], pro_s[i + 1] + 1)
    ans = 0
    for i in range(n):
        ans += pro_s[i] - s[i]
        if s[i] > pro_s[i]:
            print(-1)
            return
    print(ans)
    print(*pro_s)


T = 1
for ii in range(T):
    # print(main())
    # print(ii)
    main()
