import sys

input = lambda: sys.stdin.readline().rstrip()


def lowbit(x):
  return x & -x


n, q = map(int, input().split())

for _ in range(q):
  cur = int(input())
  s = input()
  for c in s:
    p = lowbit(cur)

    if c == 'L':
      if cur & 1:
        continue
      cur = cur ^ p ^ (p >> 1)
    elif c == 'R':
      if cur & 1:
        continue
      cur = cur ^ (p >> 1)
    else:
      if cur == (n + 1) // 2:
        continue
      cur = (cur | (p << 1)) ^ p

  print(cur)
