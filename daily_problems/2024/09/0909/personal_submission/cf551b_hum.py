from collections import Counter

a = input()
b = input()
c = input()
cnt1 = Counter(a)
cnt2 = Counter(b)
cnt3 = Counter(c)

t1 = min(cnt1[x] // cnt2[x] for x in cnt2)

res1 = 0
res2 = 0
for i in range(t1 + 1):
  cnt = Counter(cnt1)
  for x in cnt2:
    cnt[x] -= cnt2[x] * i
  t2 = min(cnt[x] // cnt3[x] for x in cnt3)
  if i + t2 > res1 + res2:
    res1 = i
    res2 = t2

res = []
for i in range(res1):
  res.append(b)
for i in range(res2):
  res.append(c)

cnt = Counter(cnt1)
for x in cnt:
  cnt[x] -= res1 * cnt2[x] + res2 * cnt3[x]
  res.append(x * cnt[x])

print(''.join(res))
