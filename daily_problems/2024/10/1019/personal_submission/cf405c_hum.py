import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
res = 0
for i in range(n):
  g = list(map(int, input().split()))
  res ^= g[i]

q = int(input())

for _ in range(q):
  s = input()
  if s[0] == '3':
    print(res, end="")
  else:
    res ^= 1
