from math import gcd

p, q = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))


def dfs(i):
  if i == n - 1:
    return a[i], 1
  x, y = dfs(i + 1)
  u = gcd(x, y)
  x //= u
  y //= u
  return a[i] * x + y, x


x, y = dfs(0)

if y * p == x * q:
  print("YES")
else:
  print("NO")
