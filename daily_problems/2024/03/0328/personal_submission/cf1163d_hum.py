from math import inf


def kmp_pre(s):
  n = len(s)
  kmp = [0] * (n + 1)
  kmp[0] = -1
  j = 0
  for i in range(1, n):
    while j >= 0 and s[i] != s[j]:
      j = kmp[j]
    j += 1
    kmp[i + 1] = j
  return kmp


c_s = input()
s = input()
t = input()
kmp_s = kmp_pre(s)
kmp_t = kmp_pre(t)

a, b = len(s), len(t)
dp = [[-inf] * b for _ in range(a)]

dp[0][0] = 0

for c in c_s:
  ndp = [[-inf] * b for _ in range(a)]
  for i in range(a):
    for j in range(b):
      tmp = 'abcdefghijklmnopqrstuvwxyz' if c == '*' else c
      for x in tmp:
        if dp[i][j] == -inf:
          continue
        diff = 0
        ii = i
        while ii >= 0 and s[ii] != x:
          ii = kmp_s[ii]
        ii += 1
        if ii == a:
          ii = kmp_s[ii]
          diff += 1

        jj = j
        while jj >= 0 and t[jj] != x:
          jj = kmp_t[jj]
        jj += 1
        if jj == b:
          jj = kmp_t[jj]
          diff -= 1
        ndp[ii][jj] = max(ndp[ii][jj], dp[i][j] + diff)

  dp = ndp

print(max((max(x) for x in dp)))
