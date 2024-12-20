n, m, k = map(int, input().split())
nums1 = list(map(int, input().split()))
nums2 = list(map(int, input().split()))

nums1.sort(reverse=True)
nums2.sort(reverse=True)

if n > m:
  print('YES')
else:
  for i in range(n):
    if nums1[i] > nums2[i]:
      exit(print('YES'))

  print('NO')
