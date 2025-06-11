import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
m = 100005
last = [-1] * m

t = [[] for _ in range(m)]
for i in range(1, m):
  for j in range(i, m, i):
    t[j].append(i)

for i in range(n):
  a, b = map(int, input().split())
  res = 0
  for v in t[a]:
    if last[v] < i - b:
      res += 1
    last[v] = i
  print(res)
