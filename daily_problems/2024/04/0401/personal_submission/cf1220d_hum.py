from collections import Counter

n = int(input())
b = list(map(int, input().split()))
cnt = Counter()
for v in b:
  cnt[v & -v] += 1

tmp = cnt.most_common()[0][0]

res = []
for v in b:
  if tmp != v & -v:
    res.append(v)

print(len(res))
print(*res)
