from collections import Counter

n = int(input())
a = list(map(int, input().split()))
cnt = Counter()
for i in range(n):
  cnt[a[i]] += 1
  while cnt[a[i]] == 2:
    del cnt[a[i]]
    cnt[2 * a[i]] += 1
    a[i] = 2 * a[i]

res = []
for x in reversed(a):
  if cnt[x]:
    res.append(x)
    del cnt[x]

print(len(res))
print(*reversed(res))
