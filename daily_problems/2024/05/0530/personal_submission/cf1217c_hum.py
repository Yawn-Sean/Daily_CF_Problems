t = int(input())
for _ in range(t):
  s = input()
  n = len(s)
  cnt = 0
  res = 0
  for i in range(n):
    if s[i] == '0':
      cnt += 1
    else:
      cur = 0
      for j in range(i, n):
        cur = (cur << 1) + int(s[j])
        if 0 <= cur - (j - i + 1) <= cnt:
          res += 1
        if cur > j - i + 1 + cnt:
          break
      cnt = 0

  print(res)
