n, m, a, b = map(int, input().split())
nums1 = list(map(int, input().split()))
nums2 = list(map(int, input().split()))
nums3 = list(map(int, input().split()))


def dis(i, j):
  return (a * a + nums1[i] * nums1[i]) ** 0.5 + (
      (b - a) * (b - a) + (nums2[j] - nums1[i]) * (nums2[j] - nums1[i])) ** 0.5 + nums3[j]


res = 10 ** 9
idx1, idx2 = -1, -1
pt = 0

for i in range(m):
  while pt < n - 1 and dis(pt, i) > dis(pt + 1, i):
    pt += 1

  nres = dis(pt, i)
  if nres < res:
    res = nres
    idx1, idx2 = pt, i

print(idx1 + 1, idx2 + 1)
