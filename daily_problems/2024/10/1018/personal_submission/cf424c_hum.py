n = int(input())
a = list(map(int, input().split()))
b = list(range(1, n)) + [0]

res = a[0]
x = [0, b[0]]
for i in range(1, n):
  x.append(x[-1] ^ b[i])
  res ^= a[i]

for i in range(2, n + 1):
  k, r = divmod(n, i)
  if k % 2:
    res ^= x[i - 1] ^ x[r]
  else:
    res ^= x[r]

print(res)
