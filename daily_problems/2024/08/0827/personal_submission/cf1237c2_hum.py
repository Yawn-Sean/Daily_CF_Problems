import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
base = 10 ** 8 + 5

d1 = dict()
for i in range(n):
  a, b, c = map(int, input().split())
  d1.setdefault(a, dict()).setdefault(b, []).append((c, i + 1))

res = []
last1 = []
for k, v in d1.items():
  last2 = []
  for k2, v2 in v.items():
    v2.sort()
    while len(v2) >= 2:
      res.append((v2.pop()[1], v2.pop()[1]))
    if v2:
      last2.append((k2, v2.pop()[1]))
  last2.sort()
  while len(last2) >= 2:
    res.append((last2.pop()[1], last2.pop()[1]))

  if last2:
    last1.append((k, last2.pop()[1]))

last1.sort()
while len(last1) >= 2:
  res.append((last1.pop()[1], last1.pop()[1]))

for x, y in res:
  print(x, y)
