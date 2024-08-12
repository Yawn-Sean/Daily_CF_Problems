import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
a = list(map(int, input().split()))
last = a[0]
right = [-1] * n
for i in range(1, n):
  if a[i] != last:
    right[i] = i - 1
  else:
    right[i] = right[i - 1]
  last = a[i]

for _ in range(m):
  l, r, x = map(int, input().split())
  l -= 1
  r -= 1
  if a[r] != x:
    print(r + 1)
  elif right[r] >= l:
    print(right[r] + 1)
  else:
    print(-1)
