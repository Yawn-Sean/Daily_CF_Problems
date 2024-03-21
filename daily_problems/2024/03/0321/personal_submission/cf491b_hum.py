import sys

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
c = int(input())
m1, m2 = float('inf'), float('inf')
m3, m4 = -float('inf'), -float('inf')
for _ in range(c):
  x, y = map(int, input().split())
  m1 = min(m1, x + y)
  m2 = min(m2, x - y)
  m3 = max(m3, x + y)
  m4 = max(m4, x - y)

h = int(input())

res = float('inf')
idx = 0
for i in range(h):
  x, y = map(int, input().split())
  cur = max(x + y - m1, x - y - m2, m3 - (x + y), m4 - (x - y))
  if res > cur:
    res, idx = cur, i + 1

print(res)
print(idx)
