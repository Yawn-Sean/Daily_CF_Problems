s = list(map(lambda x: ord(x) - ord('a'), list(input())))
n = len(s)
m = len(set(s))


def cal(x):
  cnt = [0] * 26
  c = 0
  l = 0
  res = 0
  for r in range(n):
    cnt[s[r]] += 1
    if cnt[s[r]] == 1:
      c += 1
    while c > x:
      cnt[s[l]] -= 1
      if cnt[s[l]] == 0:
        c -= 1
      l += 1
    res += r - l + 1
  return res


res = [0]
last = 0
for i in range(1, m + 1):
  t = cal(i)
  res.append(t - last)
  last = t

print(m)
for i in range(m):
  print(res[i + 1])
