n, m, k = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353

last = 0
res = 1
for i in range(m):
  v = pow(k, a[i] - last, mod)
  res = (res * v * (v + 1) // 2) % mod
  last = a[i]

res = (res * pow(k, n - 2 * a[-1], mod)) % mod

print(res)
