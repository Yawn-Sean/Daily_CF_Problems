t = ix()
for i in range(t):
    m, t = il()
    if t <= 3 * m: print(0)
    else:
        l, r = 3, t // m
        def check(mid):
            s = (t / mid - m) / 2
            return s * s / tan(pi / mid) * mid

        while l < r:
            mid = (l + r) >> 1
            if check(mid) < check(mid + 1):
                l = mid + 1
            else:
                r = mid
        print(check(l))
