import sys

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
ps = []
inf = 10 ** 15
for _ in range(n):
  l, r = map(int, input().split())
  ps.append((l, r))

pre = [(0, inf)]
for l, r in ps:
  pre.append((max(pre[-1][0], l), min(pre[-1][1], r)))

suf = [(0, inf)]
for l, r in ps[::-1]:
  suf.append((max(suf[-1][0], l), min(suf[-1][1], r)))
suf = [(0, 0)] + suf[::-1]

res = 0
for i, (l, r) in enumerate(ps, 1):
  res = max(res, min(pre[i - 1][1], suf[i + 1][1]) - max(pre[i - 1][0], suf[i + 1][0]))
print(res)
