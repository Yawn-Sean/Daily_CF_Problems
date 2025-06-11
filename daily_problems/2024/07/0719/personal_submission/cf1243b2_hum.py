t = int(input())


def f(n, s, t):
  res = []
  for i in range(n - 1):
    if s[i] != t[i]:
      for j in range(i + 1, n):
        if s[j] == s[i]:
          res.append((j + 1, i + 1))
          s[j] = t[i]
          break
      else:
        for j in range(i + 1, n):
          if t[j] == s[i]:
            res.append((n, j + 1))
            res.append((n, i + 1))
            t[j] = s[n - 1]
            s[n - 1] = t[i]
            break
        else:
          print("NO")
          return
  if s[n - 1] != t[n - 1]:
    print("NO")
  else:
    print("YES")
    print(len(res))
    for x, y in res:
      print(x, y)


for _ in range(t):
  n = int(input())
  s = list(input())
  t = list(input())
  f(n, s, t)
