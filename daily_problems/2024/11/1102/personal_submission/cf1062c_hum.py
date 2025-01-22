import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()
n, q = map(int, input().split())
s = input()
s = [int(i) for i in s]
acc = list(accumulate(s, initial=0))

mod = 10 ** 9 + 7

inv_2 = pow(2, -1, mod)
p = [1]
p2 = [1]
for i in range(n):
  p.append(p[-1] * 2 % mod)
  p2.append(p2[-1] * inv_2 % mod)

acc_p = list(accumulate(p))
acc_p2 = list(accumulate(p2))
acc_p2_2 = [1]
for i in range(1, n):
  acc_p2_2.append((acc_p2_2[-1] + p2[i] * (i + 1)) % mod)

for i in range(q):

  l, r = map(lambda x: int(x) - 1, input().split())

  c1 = acc[r + 1] - acc[l]
  length = r - l + 1

  if length <= 1:
    print(c1)
    continue
  if c1 == 0:
    print(0)
    continue
  if c1 == 1:
    print((acc_p[length - 2] + 1) % mod)
    continue
  x = p[length - 2]

  print((c1 * acc_p[length - 2] - (acc_p2[c1 - 2] * c1 - acc_p2_2[c1 - 2]) * x + c1) % mod)
