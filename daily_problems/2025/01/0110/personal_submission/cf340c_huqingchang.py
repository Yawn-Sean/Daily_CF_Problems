def main():
    n = II()
    res = LII()
    res.sort()
    s = sum(res)
    ans = 0
    tmp = 0
    for i in range(1, n):
        tmp += res[i - 1]
        ans += i * res[i] - tmp
    up = s + 2 * ans
    gc = math.gcd(up, n)
    print(up // gc, n // gc)


T = 1
for ii in range(T):
    # print(main())
    main()
