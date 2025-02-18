s = input()
s, n = s.split("=")
n = int(n)
s = '+' + ''.join(''.join(x for x in s if x != '?').strip().split())
max_total = sum([-1 if d == '-' else n for d in s])
min_total = sum([-n if d == '-' else 1 for d in s])
if min_total <= n <= max_total:
  print('Possible')
  result = [-1 if d == '-' else n for d in s]
  print(result)
  total = sum(result)
  for i in range(len(s)):
    if total <= n:
      break
    delta = min(total - n, n - 1)
    result[i] -= delta
    total -= delta
  for i in range(len(s)):
    if i:
      print(s[i], end=' ')
    print(abs(result[i]), end=' ')
  print("= " + str(n))
else:
  print('Impossible')
