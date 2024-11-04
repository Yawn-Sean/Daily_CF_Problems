import sys
from math import inf

input = lambda: sys.stdin.readline().rstrip()
n = int(input())

nums = [[-inf] * 5 for _ in range(n)]

for i in range(n):
  k = int(input())
  for _ in range(k):
    c, d = map(int, input().split())
    if c == 1:
      if d >= nums[i][0]:
        nums[i][0], nums[i][1], nums[i][2] = d, nums[i][0], nums[i][1]
      elif d >= nums[i][1]:
        nums[i][1], nums[i][2] = d, nums[i][1]
      elif d > nums[i][2]:
        nums[i][2] = d
    elif c == 2:
      if d > nums[i][3]:
        nums[i][3] = d
    else:
      if d > nums[i][4]:
        nums[i][4] = d

dp = [[-inf] * 10 for _ in range(n + 1)]

dp[0][0] = 0


def up_cnt1(i, j):
  nj = (j + 1) % 10
  if nj == 0:
    dp[i][nj] = max(dp[i][nj], dp[i - 1][j] + max(nums[i - 1][0], nums[i - 1][3], nums[i - 1][4]) * 2)
  else:
    dp[i][nj] = max(dp[i][nj], dp[i - 1][j] + max(nums[i - 1][0], nums[i - 1][3], nums[i - 1][4]))


def up_cnt2(i, j):
  a = [nums[i - 1][0], nums[i - 1][1], nums[i - 1][3]]
  a.sort(reverse=True)
  nj = (j + 2) % 10
  if nj == 0 or nj == 1:
    dp[i][nj] = max(dp[i][nj], dp[i - 1][j] + a[0] * 2 + a[1])
  else:
    dp[i][nj] = max(dp[i][nj], dp[i - 1][j] + a[0] + a[1])


def up_cnt3(i, j):
  nj = (j + 3) % 10
  if nj == 0 or nj == 1 or nj == 2:
    dp[i][nj] = max(dp[i][nj], dp[i - 1][j] + nums[i - 1][0] * 2 + nums[i - 1][1] + nums[i - 1][2])
  else:
    dp[i][nj] = max(dp[i][nj], dp[i - 1][j] + nums[i - 1][0] + nums[i - 1][1] + nums[i - 1][2])


for i in range(1, n + 1):
  dp[i][:] = dp[i - 1][:]
  for j in range(10):
    up_cnt1(i, j)
    up_cnt2(i, j)
    up_cnt3(i, j)

print(max(dp[n]))
