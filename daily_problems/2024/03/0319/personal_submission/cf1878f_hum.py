import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()


def h(v, c):
  i = 2
  while i * i <= v:
    while v % i == 0:
      v //= i
      c[i] += 1
    i += 1

  if v > 1:
    c[v] += 1


t = int(input())

for _ in range(t):
  n, q = map(int, input().split())
  old_n = n
  old_cnt = Counter()
  h(old_n, old_cnt)

  cur_cnt = old_cnt.copy()
  for _ in range(q):
    k = input().split()
    if len(k) == 2:
      x = int(k[1])
      n *= x
      h(x, cur_cnt)
      tmp = 1
      for v in cur_cnt.values():
        tmp *= (1 + v)
      if n % tmp == 0:
        print("YES")
      else:
        print("NO")
    else:
      n = old_n
      cur_cnt = old_cnt.copy()
  print()
