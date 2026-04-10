for i in range(ix()):
    n = ix()
    a = il()
    ans = n - 1
    c = m = 0
    for x in a:
        if c < 0:
            c += m
            ans += 1
        m = max(m, x)
        c -= 1
    print(ans)
