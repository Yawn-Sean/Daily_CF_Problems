n, k = map(int, input().split())
a = list(map(int, input().split()))
next_pos = list(range(n))
for i in range(n - 2, -1, -1):
  if a[i] == 1:
    next_pos[i] = next_pos[i + 1]

tot = sum(a) * k
res = 0
for i in range(n):
  p = 1
  s = 0
  j = i
  while j < n:
    if next_pos[j] == j:
      if p * a[j] > tot:
        break
      p *= a[j]
      s += a[j]
      if p == s * k:
        res += 1
      j += 1
    else:
      if p % k == 0 and 0 < p // k - s <= next_pos[j] - j:
        res += 1
      s += next_pos[j] - j
      j = next_pos[j]

print(res)
