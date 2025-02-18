import sys

input = lambda: sys.stdin.readline().rstrip()
n, x, y = map(int, input().split())
a = []
for _ in range(n):
  l, r = map(int, input().split())
  a.append((l, r))

a.sort()

sl = SortedList()
lim = x // y
res = 0
mod = 10 ** 9 + 7
for l, r in a:
  last_idx = sl.bisect_left(l) - 1
  if last_idx >= 0 and l - sl[last_idx] <= lim:
    res += (r - sl[last_idx]) * y
    res %= mod
    sl.remove(sl[last_idx])
  else:
    res += x + y * (r - l)
    res %= mod
  sl.add(r)

print(res)
