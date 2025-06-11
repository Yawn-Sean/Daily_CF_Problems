import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n, m = map(int, input().split())
  a = list(map(lambda x: int(x) - 1, input().split()))
  b = list(map(lambda x: int(x) - 1, input().split()))
  pos = [0] * n
  s = set(b)
  for i in range(n):
    pos[a[i]] = i
  mod = 998244353
  res = 1
  for x in b:
    i = pos[x]
    t = 0
    if i - 1 >= 0 and a[i - 1] not in s:
      t += 1
    if i + 1 < n and a[i + 1] not in s:
      t += 1
    res = res * t % mod
    s.remove(x)

  print(res)
