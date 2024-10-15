s = input()
n = len(s)
res = []
idx = 0
for i in range(n):
  if s[i] == '0':
    if idx == len(res):
      res.append([i + 1])
    else:
      res[idx].append(i + 1)
    idx += 1
  else:
    idx -= 1
    if idx < 0:
      print(-1)
      exit()
    res[idx].append(i + 1)

if idx != len(res):
  print(-1)
  exit()

print(len(res))
for r in res:
  print(len(r), *r)
