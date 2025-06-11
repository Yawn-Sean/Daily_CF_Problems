import sys
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
m = 9
a = []
d = defaultdict(int)
for _ in range(n):
  s = input()
  a.append(s)
  ss = set()
  for i in range(m):
    for j in range(i, m):
      ss.add(s[i:j + 1])
  for s in ss:
    d[s] += 1


def solve(s):
  for l in range(1, m + 1):
    for i in range(m):
      j = i + l
      if d[s[i:j]] == 1:
        print(s[i:j])
        return


for s in a:
  solve(s)
