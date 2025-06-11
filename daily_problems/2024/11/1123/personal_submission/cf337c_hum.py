n, m, k = map(int, input().split())

t = n // k

mod = 1000000009
if m + t <= n:
  print(m)
  exit()

t = m - (n - t)

res = m - k * t

res += (pow(2, t, mod) - 1) * 2 * k
print(res % mod)
