import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = list(map(int, input().split()))

q = int(input())
t = [[] for _ in range(n + 1)]

for i in range(q):
  k, pos = map(int, input().split())
  t[k].append((pos, i))

res = [0] * q
sl = SortedList()
for i in sorted(range(n), key=lambda x: a[x], reverse=True):
  sl.add(i)
  for p, idx in t[len(sl)]:
    res[idx] = a[sl[p - 1]]

print(*res, sep="\n")
