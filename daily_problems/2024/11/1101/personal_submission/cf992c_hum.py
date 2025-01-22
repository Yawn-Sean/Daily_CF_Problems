x, k = map(int, input().split())
if x == 0:
  print(0)
  exit()

mod = 10 ** 9 + 7
print((pow(2, k + 1, mod) * x - pow(2, k, mod) + 1) % mod)
