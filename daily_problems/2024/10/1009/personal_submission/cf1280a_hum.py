import sys

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
mod = 10 ** 9 + 7
for _ in range(t):
  x = int(input())
  s = input()
  l = 0
  while len(s) < x:
    s += s[l + 1:] * (int(s[l]) - 1)
    l += 1

  res = len(s)
  for k in range(l, x):
    res += ((res - k - 1) * (int(s[k]) - 1))
    res %= mod
  print(res)
