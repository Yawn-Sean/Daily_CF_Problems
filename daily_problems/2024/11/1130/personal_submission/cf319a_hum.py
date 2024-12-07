s = input()
n = len(s)
mod = 10 ** 9 + 7
res = 0
cnt = 1
while n > 0:
  if s[-n] == '1':
    res = (res + cnt * pow(2, 2 * n - 2, mod)) % mod
  n -= 1
  cnt = cnt * 2 % mod

print(res)
