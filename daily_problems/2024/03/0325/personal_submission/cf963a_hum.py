n, a, b, k = map(int, input().split())
s = input()
res = 0
mod = 10 ** 9 + 9
for i in range(k):
  if s[i] == '+':
    res = (res + pow(a, n - i, mod) * pow(b, i, mod)) % mod
  else:
    res = (res - pow(a, n - i, mod) * pow(b, i, mod)) % mod

q = pow(b, k, mod) * pow(a, -k, mod) % mod
if q == 1:
  print(res * (n + 1) // k % mod)
else:
  print(res * (1 - pow(q, (n + 1) // k, mod)) * (pow(1 - q, -1, mod)) % mod)
