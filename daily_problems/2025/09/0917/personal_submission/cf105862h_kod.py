def fun(a, b, mod):
    return a * pow(b, -1, mod) % mod

t = ix()
for i in range(t):
    n = ix()
    a = il()
    sa = sum(a)
    ans = sa
    for s in range(1, n):
        ans += sa * n // gcd(s, n)
    print(fun(ans, n * n, mod))
