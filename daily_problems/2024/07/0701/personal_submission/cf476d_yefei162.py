import sys
import math

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())


  n, k = MI()
  nums1 = []
  i = 1
  while len(nums1) < n:
      if i % 3:
          nums1.append(i * 2)
      i += 1

  nums2 = [i * 2 + 1 for i in range(3 * n)]
  print(nums2[-1] * k)
  i1 = i2 = 0
  for i in range(n):
      print(nums1[i1] * k, nums2[i2] * k, nums2[i2 + 1] * k, nums2[i2 + 2] * k)
      # x1 = math.gcd(nums1[i1] * k, nums2[i2] * k)
      # x2 = math.gcd(nums2[i2 + 1] * k, nums2[i2 + 2] * k)
      # print(math.gcd(x1, x2))
      i1 += 1
      i2 += 3
