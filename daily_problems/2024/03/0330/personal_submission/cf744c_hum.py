from math import inf

n = int(input())
col, c_r, c_b = [], [], []
for _ in range(n):
  c, r, b = input().split()
  col.append(c)
  c_r.append(int(r))
  c_b.append(int(b))

lim = 1 << n

cnt_r = [0] * lim
cnt_b = [0] * lim

for st in range(lim):
  for j in range(n):
    if st >> j & 1:
      if col[j] == 'R':
        cnt_r[st] += 1
      else:
        cnt_b[st] += 1

base = sum(range(n))

dp = [[inf] * lim for _ in range(base + 1)]
dp[0][0] = 0

for i in range(base + 1):
  for msk in range(lim):
    if dp[i][msk] < inf:
      for j in range(n):
        if msk >> j & 1 == 0:
          n_msk = msk | (1 << j)
          n_i = i + min(c_r[j], cnt_r[msk])
          dp[n_i][n_msk] = min(dp[n_i][n_msk], dp[i][msk] + max(0, c_b[j] - cnt_b[msk]))

sum_r = sum(c_r)
res = inf
for i in range(base + 1):
  if dp[i][-1] < inf:
    res = min(res, max(sum_r - i, dp[i][-1]))

print(res + n)
