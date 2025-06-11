import sys

input = lambda: sys.stdin.readline().rstrip()
n, q = map(int, input().split())
r = list(map(int, input().split()))
c = list(map(int, input().split()))

p1 = list(range(n))
for i in range(1, n):
  if r[i] % 2 == r[i - 1] % 2:
    p1[i] = p1[i - 1]

p2 = list(range(n))
for i in range(1, n):
  if c[i] % 2 == c[i - 1] % 2:
    p2[i] = p2[i - 1]

for _ in range(q):
  a, b, c, d = map(lambda x: int(x) - 1, input().split())
  if p1[a] == p1[c] and p2[b] == p2[d]:
    print("YES")
  else:
    print("NO")
