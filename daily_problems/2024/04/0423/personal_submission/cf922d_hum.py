import sys
from functools import cmp_to_key

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = []
for _ in range(n):
  a.append(input())


def f(s):
  res = 0
  cnt_s = 0
  for c in s:
    if c == 's':
      cnt_s += 1
    else:
      res += cnt_s
  return res


def cmp(i, j):
  return f(a[i] + a[j]) - f(a[j] + a[i])


idx = sorted(range(n), key=cmp_to_key(cmp), reverse=True)

print(f(''.join([a[i] for i in idx])))
