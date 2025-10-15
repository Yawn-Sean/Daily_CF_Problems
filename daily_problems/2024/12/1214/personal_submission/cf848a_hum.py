k = int(input())
if k == 0:
  print('a')
  exit()
res = []
s = 'a'
while k > 0:
  n = 1
  while (n + 1) * n // 2 <= k:
    n += 1
  k -= n * (n - 1) // 2
  res.append(s * n)
  s = chr(ord(s) + 1)

print(''.join(res))
