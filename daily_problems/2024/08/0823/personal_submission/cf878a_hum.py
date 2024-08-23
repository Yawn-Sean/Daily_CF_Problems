a, b = 0, 1023
n = int(input())
for _ in range(n):
  c, d = input().split()
  d = int(d)
  if c == '|':
    a |= d
    b |= d
  elif c == '&':
    a &= d
    b &= d
  else:
    a ^= d
    b ^= d

print(2)
print('&', a ^ b)
print('^', a)
