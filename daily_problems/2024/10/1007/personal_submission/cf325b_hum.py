n = int(input())
res = []
for i in range(64):
  cur = (1 << i) - 1
  if cur > n:
    break

  l, r = 1, 2 * 10 ** 9
  while l < r:
    mid = l + r + 1 >> 1
    if cur * mid + mid * (mid - 1) // 2 <= n:
      l = mid
    else:
      r = mid - 1

  if cur * l + l * (l - 1) // 2 == n and l % 2 == 1:
    res.append((cur + 1) * l)

if res:
  print(*res, sep='\n')
else:
  print(-1)
