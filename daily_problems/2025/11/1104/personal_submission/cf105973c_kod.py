N = 10 ** 6 + 1
f = [1 for _ in range(N)]
g = [1 for _ in range(N)]
for i in range(1, N):
    f[i] = f[i - 1] * i % mod
g[-1] = pow(f[-1], mod - 2, mod)
for i in range(N - 2, -1, -1):
    g[i] = g[i + 1] * (i + 1) % mod

def comb(n, m):
    if n < m or m < 0 or n < 0: return 0
    return f[n] * g[m] % mod * g[n - m] % mod

ans = [0] * (N)
for i in range(1, N):
    ans[i] = ans[i - 1] ^ 1 ^ (0 if i % 2 else comb(i, i//2))

n = ix()
for i in range(n):
    print(ans[ix()])
