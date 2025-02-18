n = int(input())
s = input()
l = len(s)

if l % n or all(c == '9' for c in s):
  k = l // n + 1
  print(('1' + '0' * (n - 1)) * k)
else:
  v = s[:n]
  if v * (l // n) > s:
    print(v * (l // n))
  else:
    v = list(v)
    for i in range(n - 1, -1, -1):
      if v[i] == '9':
        v[i] = '0'
      else:
        v[i] = chr(ord(v[i]) + 1)
        break
    print(''.join(v) * (l // n))
