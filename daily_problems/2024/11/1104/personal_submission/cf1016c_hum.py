from itertools import accumulate

n = int(input())
nums1 = list(map(int, input().split()))
nums2 = list(map(int, input().split()))

acc1 = list(accumulate(nums1, initial=0))
acc2 = list(accumulate(nums2, initial=0))

dp1 = [0] * (n + 1)
dp2 = [0] * (n + 1)

for i in range(n - 1, -1, -1):
  dp1[i] = dp1[i + 1] - (acc1[n] - acc1[i + 1]) - (acc2[n] - acc2[i + 1]) + 2 * i * nums1[i] + (2 * n - 1) * nums2[i]
  dp2[i] = dp2[i + 1] - (acc1[n] - acc1[i + 1]) - (acc2[n] - acc2[i + 1]) + 2 * i * nums2[i] + (2 * n - 1) * nums1[i]

res = dp1[0]
cur = 0

for i in range(n):
  if i % 2:
    cur += 2 * i * nums2[i] + (2 * i + 1) * nums1[i]
    res = max(res, cur + dp1[i + 1])
  else:
    cur += 2 * i * nums1[i] + (2 * i + 1) * nums2[i]
    res = max(res, cur + dp2[i + 1])

print(res)
