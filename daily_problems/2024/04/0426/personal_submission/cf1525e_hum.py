n, m = map(int, input().split())
dist = [list(map(int, input().split())) for _ in range(n)]

mod = 998244353

inv = 1
for i in range(1, n + 1):
  inv = (inv * i) % mod
inv = pow(inv, -1, mod)

res = 0
for j in range(m):
  cnt = [0] * n
  for i in range(n):
    if dist[i][j] >= 2:
      cnt[dist[i][j] - 2] += 1

  cur = 1
  cur_cnt = 0
  for i in range(n - 1, -1, -1):
    cur_cnt += cnt[i]
    cur = (cur * cur_cnt) % mod
    cur_cnt -= 1

  res = (res + 1 - cur * inv) % mod

print(res)
