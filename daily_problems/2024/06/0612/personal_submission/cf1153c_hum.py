n = int(input())
s = input()
if n % 2:
  print(":(")
  exit()

c1 = s.count('(')
c2 = s.count(')')
n1 = n // 2 - c1
n2 = n // 2 - c2
t = 0
res = []
for i in range(n):
  if s[i] == '(':
    t += 1
    res.append('(')
  elif s[i] == ')':
    t -= 1
    res.append(')')
  else:
    if n1 > 0:
      t += 1
      n1 -= 1
      res.append('(')
    elif n2 > 0:
      t -= 1
      n2 -= 1
      res.append(')')

  if i != n - 1 and t <= 0:
    print(":(")
    exit()
if t != 0:
  print(":(")
else:
  print(''.join(res))
