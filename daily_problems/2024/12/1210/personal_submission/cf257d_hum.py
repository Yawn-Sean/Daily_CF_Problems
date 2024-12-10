n = int(input())
a = list(map(int, input().split()))

s = ['.'] * n
t = 0
for i in range(n - 1, -1, -1):
  if t < 0:
    s[i] = '+'
    t += a[i]
  else:
    s[i] = '-'
    t -= a[i]

if t < 0:
  for i in range(n):
    if s[i] == '-':
      s[i] = '+'
    else:
      s[i] = '-'

print(''.join(s))
