import sys

input = lambda: sys.stdin.readline().rstrip()

x, k = map(int, input().split())

t = []
for _ in range(k):
  a = list(map(int, input().split()))
  need = 0
  s = 0
  m = 0
  p_m = 0
  for v in a[1:]:
    s += v
    need = min(need, s)
    m = max(m, s)
    if m > p_m:
      t.append((-need, m - p_m))
      p_m = m

t.sort()
for need, m in t:
  if x >= need:
    x += m
  else:
    break
print(x)
