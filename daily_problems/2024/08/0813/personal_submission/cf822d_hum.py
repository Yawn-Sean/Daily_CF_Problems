t, l, r = map(int, input().split())

prime_factor = list(range(r + 1))
for i in range(2, r + 1):
  if prime_factor[i] == i:
    for j in range(i * i, r + 1, i):
      if prime_factor[j] == j:
        prime_factor[j] = i

mod = 10 ** 9 + 7
f = [0] * (r + 1)
for i in range(2, r + 1):
  p = prime_factor[i]
  f[i] = (f[i // p] + i * (p - 1) // 2) % mod

res = 0
for i in range(r, l - 1, -1):
  res = (res * t + f[i]) % mod

print(res)
