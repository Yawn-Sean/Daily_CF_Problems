import sys

input = lambda: sys.stdin.readline().rstrip()

t = int(input())


def solve():
  s = input()
  n = len(s)
  msk = 0
  for i in s:
    msk ^= 1 << int(i)

  for i in range(n - 1, -1, -1):
    msk ^= 1 << int(s[i])

    for j in range(int(s[i]) - 1, -1, -1):
      if i == 0 and j == 0:
        continue
      cur = msk ^ (1 << j)
      need = []
      for k in range(10):
        if cur >> k & 1:
          need.append(k)

      if n - (i + 1) >= len(need):
        need.extend([9] * (n - (i + 1) - len(need)))
        need.sort(reverse=True)
        res = s[:i] + str(j) + "".join(map(str, need))
        print(res)
        return

  print("9" * ((n - 1) // 2 * 2))


for _ in range(t):
  solve()
