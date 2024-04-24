def q(x, y):
  print("?", x, y, flush=True)
  return int(input())


d1 = q(1, 1)
d2 = q(10 ** 9, 1)
d3 = q(1, 10 ** 9)
x_mid = (d1 - d2 + 10 ** 9 + 1) // 2
d4 = q(x_mid, 1)
print('!', d1 - d4 + 1, d4 + 1, d4 - d2 + 10 ** 9, d1 - d4 - d3 + 10 ** 9, flush=True)
