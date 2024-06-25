from collections import Counter

n, q = map(int, input().split())
a = list(map(int, input().split()))
right = dict()
for i in range(n):
  right[a[i]] = i


def f(l, r):
  cnt = Counter()
  for i in range(l, r):
    cnt[a[i]] += 1
  return r - l - cnt.most_common(1)[0][1]


m = right[a[0]]
last = 0
res = 0
for i in range(n + 1):
  if i > m:
    res += f(last, i)
    last = i
  if i < n:
    m = max(m, right[a[i]])

print(res)
