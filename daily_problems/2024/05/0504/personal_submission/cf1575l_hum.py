from bisect import bisect_right

n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))

tmp = [[] for _ in range(n)]

for i in range(n):
  if i - a[i] >= 0:
    tmp[a[i]].append(i - a[i])

lis = []

for i in range(n):
  for j in reversed(tmp[i]):
    x = bisect_right(lis, j)
    if x < len(lis):
      lis[x] = j
    else:
      lis.append(j)

print(len(lis))
