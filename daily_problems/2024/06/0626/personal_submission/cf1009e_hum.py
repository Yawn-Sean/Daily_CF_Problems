n = int(input())
a = list(map(int, input().split()))

mod = 998244353
p2 = [1] * (n + 1)
for i in range(n):
  p2[i + 1] = p2[i] * 2 % mod

res = 0
for i in range(n):
  res += a[i] * (p2[n - i - 1] + (n - i - 1) * p2[n - i - 2])
  res %= mod

print(res)
