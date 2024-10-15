import sys

input = lambda: sys.stdin.readline().rstrip()
n, x = map(int, input().split())
l, r = x, x
ans = 0

for _ in range(n):
  nl, nr = map(int, input().split())
  if l > nr:
    ans += l - nr
    l, r = nr, l
  elif r < nl:
    ans += nl - r
    l, r = r, nl
  else:
    l = max(nl, l)
    r = min(nr, r)

print(ans)
