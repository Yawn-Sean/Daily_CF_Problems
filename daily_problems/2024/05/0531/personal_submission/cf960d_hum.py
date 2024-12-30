import sys

input = lambda: sys.stdin.readline().rstrip()

shifts = [0] * 61
n = int(input())
for _ in range(n):
  q = list(map(int, input().split()))
  if q[0] == 1:
    idx = q[1].bit_length()
    k = q[2]
    shifts[idx] += k
    shifts[idx] %= 1 << (idx - 1)
  elif q[0] == 2:
    idx = q[1].bit_length()
    k = q[2]
    for i in range(idx, 61):
      k %= 1 << (i - 1)
      shifts[i] += k
      shifts[i] %= 1 << (i - 1)
      k *= 2
  else:
    x = q[1]
    idx = x.bit_length()

    pos = (x - (1 << idx - 1) + shifts[idx]) % (1 << idx - 1)
    res = []

    for i in range(idx, 0, -1):
      res.append((1 << i - 1) + (pos - shifts[i]) % (1 << i - 1))
      pos //= 2

    print(*res)
