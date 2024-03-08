# tle
import sys

input = lambda: sys.stdin.readline().strip()

memo = [[[-1] * (1 << base) for _ in range(60)] for base in range(11)]


def h(v, base):
  res = []
  while v:
    res.append(v % base)
    v //= base
  return res


def dp(num, n):
  def __dfs(i, st, limit, lead):
    if i == -1:
      return int(st == 0)

    if not limit and not lead and memo[b][i][st] != -1:
      return memo[b][i][st]

    res = 0
    if lead:
      res = __dfs(i - 1, st, False, True)

    up = num[i] if limit else b - 1
    low = 1 if lead else 0

    for j in range(low, up + 1):
      res += __dfs(i - 1, st ^ (1 << j), limit and j == up, False)

    if not limit and not lead:
      memo[b][i][st] = res

    return res

  return __dfs(n - 1, 0, True, True)


q = int(input())
for _ in range(q):
  b, l, r = map(int, input().split())
  r_l = h(l - 1, b)
  r_r = h(r, b)
  l1, l2 = len(r_l), len(r_r)
  r_l += [0] * (l2 - l1)
  print(dp(r_r, l2) - dp(r_l, l1))
