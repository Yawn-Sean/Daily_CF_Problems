def CF895B():
    n, x, k = MII()
    a = LII()
    a.sort()
    ans = 0
    for i, v in enumerate(a):
        y = (v - 1) // x * x
        r1 = bisect_left(a, fmax(v, y + x * k))
        r2 = bisect_left(a, y + x * (k + 1)) - 1
        ans += r2 - r1 + 1
    print(ans)
