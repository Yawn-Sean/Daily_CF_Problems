def solve():
    n = I()
    a = [0] + LI()
    for i in range(1, n + 1):
        a[i] += a[i - 1]

    pr = [0] * (n + 5)
    su = [0] * (n + 5)
    ans = 0
    for i in range(1, n + 1):
        pr[i] = pr[i - 1] + a[i]
    for i in range(n, 0, -1):
        su[i] = su[i + 1] + a[i]
    for d in range(1, n + 1):
        r = n - d
        l = d
        ans += ((su[l] - pr[r]) / d)
    D = n * (n + 1) // 2
    ans /= D
    print(f"{ans:.8f}")
