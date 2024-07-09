n = int(input())
s1 = input()
s2 = input()
a, b, c, d = [], [], [], []

for i in range(n):
  if s1[i] == '0' and s2[i] == '0':
    a.append(i + 1)
  elif s1[i] == '0' and s2[i] == '1':
    b.append(i + 1)
  elif s1[i] == '1' and s2[i] == '0':
    c.append(i + 1)
  else:
    d.append(i + 1)

for i in range(len(c) + 1):
  for j in range(len(d) + 1):
    p1 = i + j
    p2 = len(d) - j
    if p1 >= p2:
      if p2 + len(b) >= p1 and p1 + len(b) - (p1 - p2) <= n // 2 and p1 + len(b) - (p1 - p2) + len(a) >= n // 2:
        res = []
        for k in range(i):
          res.append(c[k])
        for k in range(j):
          res.append(d[k])
        for k in range(len(b) - (p1 - p2)):
          res.append(b[k])
        if len(res) <= n // 2:
          res.extend(a[:n // 2 - len(res)])
        print(*res)
        exit()

print(-1)
