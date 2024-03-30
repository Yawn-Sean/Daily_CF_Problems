n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))

m = min(n, 125)
right = [[[n + 1] * (m + 2) for _ in range(n + 1)] for _ in range(8)]

for i in range(8):
  for j in range(n):
    right[i][j][0] = j - 1
    cnt = 0
    for k in range(j, n):
      if a[k] == i:
        cnt += 1
      if cnt > m:
        break
      right[i][j][cnt] = min(right[i][j][cnt], k)

lim = 1 << 8
res = len(set(a))

for c in range(1, m + 1):
  dp = [[n] * lim for _ in range(9)]
  # cnt,msk
  dp[0][0] = -1

  for cc in range(9):
    for st in range(lim):
      if dp[cc][st] < n:
        for i in range(8):
          if st >> i & 1 == 0:
            dp[cc][st | 1 << i] = min(dp[cc][st | 1 << i], right[i][dp[cc][st] + 1][c])
            if cc + 1 < 9:
              dp[cc + 1][st | 1 << i] = min(dp[cc + 1][st | 1 << i], right[i][dp[cc][st] + 1][c + 1])

        if st == lim - 1:
          res = max(res, c * 8 + cc)
print(res)
