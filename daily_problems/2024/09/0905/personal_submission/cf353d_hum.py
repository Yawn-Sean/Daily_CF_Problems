s = input()
res = 0
cnt = 0
for c in s:
  if c == 'M':
    cnt += 1
  elif cnt > 0:
    res = max(res + 1, cnt)
print(res)
