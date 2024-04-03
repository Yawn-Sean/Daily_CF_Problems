import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
t1, t2 = [], []
for i in range(1, n + 1):
  a, b = map(int, input().split())
  if a < b:
    t1.append((a, b, i))
  else:
    t2.append((a, b, i))

if len(t1) >= len(t2):
  print(len(t1))
  t1.sort(key=lambda x: (-x[1]))
  print(*[i[2] for i in t1])
else:
  print(len(t2))
  t2.sort(key=lambda x: x[1])
  print(*[i[2] for i in t2])
