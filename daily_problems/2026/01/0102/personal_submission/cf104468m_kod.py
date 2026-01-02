M = 2 * 10 ** 5
f = Factorial(M, mod)
t = ix()
for _ in range(t):
    n, k = il()
    s = il()
    s = set(s)
    s.add(n)
    t = 1
    ans = f.fac(n)
    for x in range(1, n + 1):
        if x in s:
            ans = ans * f.fac_inv(t) % mod
            t = 1
        else:
            t += 1
    print(ans)
