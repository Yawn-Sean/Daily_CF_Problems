from collections import Counter

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cnt = Counter(a)

res = 0
vis = [0] * n
for x in cnt:
  if cnt[x] >= 2:
    for i in range(n):
      if not vis[i] and x & a[i] == a[i]:
        res += b[i]
        vis[i] = 1

print(res)
