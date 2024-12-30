import sys

input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
ls, rs = [], []

vis = set()
for _ in range(m):
  l, r = map(lambda x: int(x) - 1, input().split())
  if l > r:
    l, r = r, l
  ls.append(l)
  rs.append(r)
  vis.add((l, r))


def check(x):
  for i in range(m):
    nl = (ls[i] + x) % n
    nr = (rs[i] + x) % n
    if nl > nr:
      nl, nr = nr, nl
    if (nl, nr) not in vis:
      return False

  return True


t = n
for i in range(2, n + 1):
  if t % i == 0:
    while t % i == 0:
      t //= i
    if check(n // i):
      print("Yes")
      exit()

print("No")
