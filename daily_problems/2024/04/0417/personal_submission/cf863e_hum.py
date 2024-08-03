# https://codeforces.com/contest/863/submission/257051352
import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
xs, ys = [], []
for _ in range(n):
  x, y = map(int, input().split())
  xs.append(x)
  ys.append(y)
t = {v: i for i, v in enumerate(sorted(set(xs + ys + [x + 1 for x in ys])))}
m = len(t)
s = [0] * (m + 1)

for i in range(n):
  s[t[xs[i]]] += 1
  s[t[ys[i]] + 1] -= 1

for i in range(1, m + 1):
  s[i] += s[i - 1]

table = make_sparse_table(s)
for i in range(n):
  if get_min(t[xs[i]], t[ys[i]]) >= 2:
    print(i + 1)
    break
else:
  print(-1)
