fin = open('input.txt', 'r')
fout = open('output.txt', 'w')

input = lambda: fin.readline().strip()


def print(x):
  fout.write(str(x))


n = int(input())
a, b = map(int, input().split())
nums = [0] + list(map(int, input().split()))

tot = sum(nums)
inf = 10 ** 9

dp = [[inf] * (tot + 1) for _ in range(2)]

dp[0][0] = 0
dp[1][0] = 0

for i in range(1, n + 1):
  cost = min(nums[i], nums[i - 1])
  ndp = [[inf] * (tot + 1) for _ in range(2)]
  for j in range(2):
    for c in range(tot + 1):
      for nj in range(2):
        if c + nums[i] * nj <= tot:
          ndp[nj][c + nums[i] * nj] = min(ndp[nj][c + nums[i] * nj], dp[j][c] + (j ^ nj) * cost)
  dp = ndp

res = inf
for j in range(2):
  for c in range(tot + 1):
    if c <= a and tot - c <= b:
      res = min(res, dp[j][c])

print(res if res < inf else -1)
