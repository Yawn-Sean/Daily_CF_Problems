s = input()
s = [1 if i == 'R' else -1 for i in s]
n = len(s)
l, r = 0, 0
cur = 0
for i in range(n - 1):
  cur += s[i]
  l = min(l, cur)
  r = max(r, cur)
cur += s[-1]

if cur < l or cur > r:
  print(1)
  exit()

if s[-1] == -1:
  l, r = 0, n
  while l < r:
    mid = l + r + 1 >> 1
    cur = 0
    left = 0
    for i in range(n - 1):
      cur += s[i]
      if cur == mid:
        cur = mid - 1
      left = min(left, cur)
    cur += s[-1]
    if cur < left:
      l = mid
    else:
      r = mid - 1
  print(l)

else:
  l, r = -n, 0
  while l < r:
    mid = (l + r) // 2
    cur = 0
    right = 0
    for i in range(n - 1):
      cur += s[i]
      if cur == mid:
        cur = mid + 1
      right = max(right, cur)
    cur += s[-1]
    if cur > right:
      r = mid
    else:
      l = mid + 1
  print(abs(l))
