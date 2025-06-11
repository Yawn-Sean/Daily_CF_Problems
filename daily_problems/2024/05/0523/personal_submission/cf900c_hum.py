import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())

p = list(map(lambda x: int(x) - 1, input().split()))

m1, m2 = -1, -1

cnt = [0] * n
use = [0] * n
for x in p:
  if x > m1:
    use[x] = 1
  if m1 > x > m2:
    cnt[m1] += 1
  if x > m1:
    m1, m2 = x, m1
  elif x > m2:
    m2 = x

m = 1
res = 0
for i in range(n):
  if cnt[i] > m:
    res = i
    m = cnt[i]

if m != 1:
  print(res + 1)
  exit()
else:
  for i in range(n):
    if use[i] == 0:
      print(i + 1)
      exit()

print(1)
