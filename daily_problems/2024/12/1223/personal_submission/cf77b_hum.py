t = int(input())
outs = []

for _ in range(t):
  a, b = map(int, input().split())
  if b == 0:
    outs.append(1)
  elif a == 0:
    outs.append(0.5)
  elif b > a / 4:
    outs.append(0.5 + a / 16 / b)
  else:
    outs.append(1 - b / a)

print('\n'.join(map(str, outs)))
