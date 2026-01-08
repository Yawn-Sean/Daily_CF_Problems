M = 3 * 10 ** 5
f = [1] + [0] * M
for i in range(1, M + 1):
    f[i] = f[i - 1] * i % mod

t = ix()
for _ in range(t):
    n = ix()
    ans = f[n // 2] * f[n - n // 2] % mod
    if n % 2 == 0:
        ans = ans * (n // 2 + 1) % mod
    else:
        ans = ans * ((n // 2 + 1) * ( n // 2 + 2) // 2) % mod
    print(ans)
