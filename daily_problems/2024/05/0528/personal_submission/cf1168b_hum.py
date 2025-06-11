s = input()
n = len(s)
res = 0
r = n
for i in range(n - 1, -1, -1):
  for k in range(1, 100):
    if i + 2 * k < n:
      if s[i] == s[i + k] == s[i + 2 * k]:
        r = min(r, i + 2 * k)
        break
  res += n - r

print(res)
