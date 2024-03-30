import sys

input = lambda: sys.stdin.readline().rstrip()

from collections import defaultdict

n = int(input())

m = defaultdict(int)
res = 0
l = [0]
for i in range(26):
  l.append(1 << i)
for _ in range(n):
  s = input()
  cur = 0
  for c in s:
    cur ^= 1 << (ord(c) - ord('a'))
  for v in l:
    res += m[cur ^ v]
  m[cur] += 1
print(res)
