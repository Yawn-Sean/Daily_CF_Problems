from itertools import accumulate
from math import inf

w, l = map(int, input().split())
a = list(map(int, input().split()))
s = list(accumulate(a, initial=0))

res = inf
for i in range(l, w):
  res = min(res, s[i] - s[i - l])

print(res)
