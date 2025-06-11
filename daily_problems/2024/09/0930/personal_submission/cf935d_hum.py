n, m = map(int, input().split())
nums1 = list(map(int, input().split()))
nums2 = list(map(int, input().split()))
res = 0
prob = 1
mod = 10 ** 9 + 7

inv2 = pow(2, -1, mod)
invm = pow(m, -1, mod)

for i in range(n):
  if nums1[i]:
    if nums2[i]:
      if nums1[i] > nums2[i]:
        res = (res + prob) % mod
        break
      elif nums1[i] < nums2[i]:
        break
    else:
      res += prob * (nums1[i] - 1) % mod * invm % mod
      if res >= mod:
        res -= mod
      prob = prob * invm % mod
  else:
    if nums2[i]:
      res += prob * (m - nums2[i]) % mod * invm % mod
      if res >= mod:
        res -= mod
      prob = prob * invm % mod
    else:
      res += prob * (m - 1) % mod * inv2 % mod * invm % mod
      if res >= mod:
        res -= mod
      prob = prob * invm % mod

print(res)
