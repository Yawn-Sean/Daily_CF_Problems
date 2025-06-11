import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
res = n
d = [1] * n
mod = 998244353
for _ in range(n - 1):
  a, b = map(lambda x: int(x) - 1, input().split())
  res = res * d[a] * d[b] % mod
  d[a] += 1
  d[b] += 1

print(res)
