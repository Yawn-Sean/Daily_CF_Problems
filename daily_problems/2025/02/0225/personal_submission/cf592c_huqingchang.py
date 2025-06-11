def main():
    t, w, b = MII()
    if w == b:
        exit(print("1/1"))
    lc = math.lcm(w, b)
    up = min(w, b) - 1
    ans = (t + 1) // lc * (up + 1) - 1
    rest = (t + 1) % lc
    ans += min(up + 1, rest)
    gc = math.gcd(ans, t)
    print(f'{ans // gc}/{t // gc}')


T = 1
for ii in range(T):
    # print(main())
    # print(ii + 1)
    main()
