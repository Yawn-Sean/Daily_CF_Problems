s = input()
n = len(s)
res = 0
for i in range(0, 10 ** 8, 25):
  t = str(i)
  if len(t) > n: break
  if len(t) < n: continue
  x = -1
  p = 1
  for j in range(n):
    if s[j] == '_':
      continue
    if s[j] == 'X':
      if x == -1:
        x = int(t[j])
      else:
        if int(t[j]) != x:
          p = 0
          break
    else:
      if s[j] != t[j]:
        p = 0
        break
  res += p
print(res)
