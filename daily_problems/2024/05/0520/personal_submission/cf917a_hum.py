s = input()
n = len(s)
res = 0
for i in range(n):
  acc = 0
  num = 0
  for j in range(i, n):
    if s[j] == '(':
      acc += 1
    elif s[j] == ')':
      acc -= 1
    else:
      if acc >= 0:
        acc -= 1
        num += 1
      else:
        acc += 1

    if acc < 0 and num > 0:
      acc += 2
      num -= 1
    if acc < 0 and num == 0:
      break
    if acc == 0:
      res += 1

print(res)
