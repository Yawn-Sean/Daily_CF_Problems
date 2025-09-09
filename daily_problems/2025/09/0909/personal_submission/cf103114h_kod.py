C = Combinatorics(MX, MOD)
t = ix()
for i in range(t):
    n, m = il()
    if n == m == 1:
        print(1)
        continue
    if 2 * n > m:
        print(0)
        continue
    ans = m * C.comb(m - n - 1, n - 1) * C.fact(n - 1) % MOD
    print(ans)



