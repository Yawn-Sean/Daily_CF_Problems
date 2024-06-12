n, d = map(int, input().split())
a = list(map(int, input().split()))
s1, s2 = 0, 0
res = 0

for x in a:
  if x:
    s1 += x
    s2 += x
    if s1 > d:
      print('-1')
      exit()
    if s2 > d:
      s2 = d
  else:
    if s2 < 0:
      s2 = d
      res += 1
    if s1 < 0:
      s1 = 0

print(res)
