n = int(input())
s = input()

asterisks = []
packmen = []

for i in range(n):
  if s[i] == '*':
    asterisks.append(i)
  elif s[i] == 'P':
    packmen.append(i)

l, r = 0, 2 * 10 ** 5
k = len(asterisks)

while l < r:
  m = (l + r) // 2

  pt = 0
  for p in packmen:
    if abs(asterisks[pt] - p) > m:
      continue

    left = max(0, p - asterisks[pt])
    right = p + max((m - left) // 2, m - left * 2)

    while pt < k and asterisks[pt] <= right:
      pt += 1

    if pt == k:
      break

  if pt == k:
    r = m
  else:
    l = m + 1

print(l)
