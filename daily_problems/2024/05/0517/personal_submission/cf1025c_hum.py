s = input()
s += s
n = len(s)
cur = 1
res = 1
for i in range(1, n):
  if s[i] != s[i - 1]:
    cur += 1
  else:
    cur = 1
  res = max(res, cur)

print(min(res, n // 2))
