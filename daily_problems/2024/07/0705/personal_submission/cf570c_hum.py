n, m = map(int, input().split())
s = list(input())
i = 0
res = 0
while i < n:
  j = i
  if s[i] == '.':
    while j + 1 < n and s[j + 1] == s[i]:
      j += 1
    res += j - i
  i = j + 1

for _ in range(m):
  i, c = input().split()
  i = int(i) - 1
  if c != '.':
    if s[i] == '.':
      if i - 1 >= 0 and s[i - 1] == '.':
        res -= 1
      if i + 1 < n and s[i + 1] == '.':
        res -= 1
  else:
    if s[i] != '.':
      if i - 1 >= 0 and s[i - 1] == '.':
        res += 1
      if i + 1 < n and s[i + 1] == '.':
        res += 1

  s[i] = c

  print(res)
