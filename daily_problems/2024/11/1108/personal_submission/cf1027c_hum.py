import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  cnt = Counter(a)
  keys = [k for k, v in cnt.items() if v >= 2]
  keys.sort()
  if cnt[keys[0]] >= 4:
    res = (keys[0], keys[0])
  else:
    res = (keys[0], keys[1])

  for i in range(1, len(keys)):
    if cnt[keys[i]] >= 4:
      x, y = keys[i], keys[i]
    else:
      x, y = keys[i - 1], keys[i]

    if (res[0] + res[1]) ** 2 * x * y > (x + y) ** 2 * res[0] * res[1]:
      res = (x, y)

  print(res[0], res[0], res[1], res[1])
