for _ in range(times):
    d, m = il()
    t = 1
    ans = 1
    while d:
        if d < t:
            ans = ans * (d + 1) % m
            break
        ans = ans * (t + 1) % m
        d -= t
        t <<= 1
    print((ans - 1) % m)
