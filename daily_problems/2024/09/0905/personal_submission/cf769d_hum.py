from collections import Counter

n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt = Counter(a)
if k == 0:
  print(sum(x * (x - 1) // 2 for x in cnt.values()))
  exit()

v = [i for i in range(1 << 14) if i.bit_count() == k]
res = 0
for i in cnt:
  for j in v:
    res += cnt[i] * cnt[i ^ j]
print(res // 2)
