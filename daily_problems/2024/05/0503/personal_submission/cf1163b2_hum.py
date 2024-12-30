from collections import Counter

n = int(input())
a = list(map(int, input().split()))
cnt = Counter()
cnt_cnt = Counter()

res = 1
for i in range(1, n + 1):
  t = a[i - 1]
  cnt[t] += 1
  cnt_cnt[cnt[t]] += 1
  if cnt[t] * cnt_cnt[cnt[t]] == i and i != n:
    res = i + 1
  if cnt[t] * cnt_cnt[cnt[t]] == i - 1:
    res = i

print(res)
